#!/usr/bin/env bash
# Generate workshop.vdf for this mod, ready for `steamcmd +workshop_build_item`.
#
# Identical across all Baldies_* mod repos — never hardcodes a mod name,
# only ever reads/writes files relative to its own location (the repo root)
# and the current directory's own name.
#
# Usage:
#   ./create_vdf.sh
#
# Reads:
#   mod.cpp             - name, overview, version
#   docs/CHANGELOG.md   - latest "## vX.Y.Z - DATE" section as the changenote
#   workshop_id.txt     - existing publishedfileid (absent/empty => new item)
#   docs/preview.png    - Workshop thumbnail (validated: PNG/JPEG, square,
#                          >=195x195px, <1MB)
#   build/@<ModName>/   - the already-built, signed mod folder to upload
#
# Writes:
#   workshop.vdf         (gitignored — embeds a local absolute path)
#
# NOTE: The exact set of fields/values DayZ's Workshop backend actually
# requires is not confirmed — this follows the generic Steamworks
# workshop_build_item schema. The first real upload_to_workshop.sh run is
# the real-world test of whether this is correct for DayZ.

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")" && pwd)"
MOD_NAME="$(basename "$REPO_ROOT")"
MOD_CPP="$REPO_ROOT/mod.cpp"
CHANGELOG="$REPO_ROOT/docs/CHANGELOG.md"
PREVIEW="$REPO_ROOT/docs/preview.png"
ID_FILE="$REPO_ROOT/workshop_id.txt"
CONTENT_DIR="$REPO_ROOT/build/@${MOD_NAME}"
VDF_PATH="$REPO_ROOT/workshop.vdf"

APPID=221100

[[ -f "$MOD_CPP" ]] || { echo "ERROR: mod.cpp not found at $MOD_CPP" >&2; exit 1; }
[[ -f "$CHANGELOG" ]] || { echo "ERROR: CHANGELOG.md not found at $CHANGELOG" >&2; exit 1; }
[[ -d "$CONTENT_DIR" ]] || {
    echo "ERROR: built mod folder not found at $CONTENT_DIR" >&2
    echo "        Run ./build.sh first." >&2
    exit 1
}

# ---- preview image validation ------------------------------------------

if [[ ! -f "$PREVIEW" ]]; then
    echo "ERROR: preview image not found at $PREVIEW" >&2
    echo "        Steam Workshop requires a square PNG/JPEG, >=195x195px, <1MB." >&2
    exit 1
fi
command -v identify >/dev/null 2>&1 || {
    echo "ERROR: ImageMagick 'identify' not found on PATH (needed to validate $PREVIEW)" >&2
    exit 1
}

IMG_INFO="$(identify -format "%w %h %m" "$PREVIEW" 2>/dev/null)" || {
    echo "ERROR: could not read image info from $PREVIEW (is it a valid image?)" >&2
    exit 1
}
read -r P_WIDTH P_HEIGHT P_FORMAT <<< "$IMG_INFO"

case "$P_FORMAT" in
    PNG|JPEG|JPG) ;;
    *)
        echo "ERROR: $PREVIEW is format '$P_FORMAT', must be PNG or JPEG" >&2
        exit 1
        ;;
esac
if [[ "$P_WIDTH" -ne "$P_HEIGHT" ]]; then
    echo "ERROR: $PREVIEW is ${P_WIDTH}x${P_HEIGHT}, must be square" >&2
    exit 1
fi
if [[ "$P_WIDTH" -lt 195 ]]; then
    echo "ERROR: $PREVIEW is ${P_WIDTH}x${P_HEIGHT}, must be at least 195x195px" >&2
    exit 1
fi
P_BYTES="$(stat -c%s "$PREVIEW")"
if [[ "$P_BYTES" -ge 1048576 ]]; then
    echo "ERROR: $PREVIEW is $P_BYTES bytes, must be under 1MB" >&2
    exit 1
fi

# ---- publishedfileid ------------------------------------------------------

PUBLISHED_ID="0"
if [[ -f "$ID_FILE" ]]; then
    CANDIDATE="$(tr -d '[:space:]' < "$ID_FILE")"
    if [[ -n "$CANDIDATE" ]]; then
        if ! [[ "$CANDIDATE" =~ ^[0-9]+$ ]]; then
            echo "ERROR: $ID_FILE contains a non-numeric value: '$CANDIDATE'" >&2
            exit 1
        fi
        PUBLISHED_ID="$CANDIDATE"
    fi
fi

if [[ "$PUBLISHED_ID" == "0" ]]; then
    echo "==> No existing workshop_id.txt (or it's empty) — this will be a NEW Workshop item."
else
    echo "==> Updating existing Workshop item $PUBLISHED_ID"
fi

# ---- build the vdf (python for safe KeyValues string escaping) -----------

python3 - "$MOD_CPP" "$CHANGELOG" "$VDF_PATH" \
    "$APPID" "$CONTENT_DIR" "$PREVIEW" "$PUBLISHED_ID" <<'PYEOF'
import re
import sys

mod_cpp, changelog, vdf_path, appid, content_dir, preview, published_id = sys.argv[1:8]


def read_field(text, key):
    m = re.search(rf'^{re.escape(key)}\s*=\s*"([^"]*)"\s*;', text, re.MULTILINE)
    if not m:
        sys.exit(f"ERROR: field '{key}' not found in {mod_cpp}")
    return m.group(1)


with open(mod_cpp) as f:
    mod_text = f.read()

name = read_field(mod_text, "name")
overview = read_field(mod_text, "overview")
version = read_field(mod_text, "version")

with open(changelog) as f:
    changelog_text = f.read()

# First "## vX.Y.Z - DATE" heading (skip "## Unreleased").
sections = re.findall(
    r'^## (v[\d.]+ - [\d-]+)\n(.*?)(?=^## |\Z)',
    changelog_text,
    re.MULTILINE | re.DOTALL,
)
if not sections:
    sys.exit(
        f"ERROR: no '## vX.Y.Z - DATE' section found in {changelog}. "
        f"Run ./bump_mod_version.sh first."
    )

heading, body = sections[0]
changelog_version = heading.split(" - ", 1)[0].lstrip("v")
if changelog_version != version:
    sys.exit(
        f"ERROR: mod.cpp version ({version}) does not match latest CHANGELOG "
        f"entry ({changelog_version}). Run ./bump_mod_version.sh so both are "
        f"in sync before publishing."
    )

lines = [ln.strip() for ln in body.strip().splitlines() if ln.strip()]
changenote = " ".join(lines) if lines else f"Release {version}"


def esc(s):
    return s.replace("\\", "\\\\").replace('"', '\\"')


fields = {
    "appid": appid,
    "contentfolder": content_dir,
    "previewfile": preview,
    "visibility": "0",  # 0 = Public (generic Steamworks Workshop schema)
    "title": name,
    "description": overview,
    "changenote": changenote,
    "publishedfileid": published_id,
}

with open(vdf_path, "w") as f:
    f.write('"workshopitem"\n{\n')
    for key, value in fields.items():
        f.write(f'\t"{key}"\t\t"{esc(value)}"\n')
    f.write('}\n')

print(f"==> Wrote {vdf_path}")
print(f"    title:       {name}")
print(f"    version:     {version}")
print(f"    changenote:  {changenote}")
print(f"    publishedfileid: {published_id}")
PYEOF
