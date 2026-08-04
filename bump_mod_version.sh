#!/usr/bin/env bash
# Bump this mod's version in mod.cpp and finalize docs/CHANGELOG.md.
#
# This script is identical across all Baldies_* mod repos — it never
# hardcodes a mod name, only ever reads/writes files relative to its own
# location (the repo root).
#
# Usage:
#   ./bump_mod_version.sh major|minor|patch
#
# What it does:
#   1. Reads the current `version = "X.Y.Z"` from mod.cpp (a bare "X.Y" is
#      auto-migrated to "X.Y.0" the first time this runs).
#   2. Computes the next version for the given bump type and writes it back.
#   3. In docs/CHANGELOG.md, renames the top "## Unreleased" heading into a
#      dated, versioned heading ("## vX.Y.Z - YYYY-MM-DD") and opens a fresh
#      empty "## Unreleased" section above it, so future edits have
#      somewhere to go and create_vdf.sh has a versioned entry to read.

set -euo pipefail

BUMP="${1:-}"
if [[ "$BUMP" != "major" && "$BUMP" != "minor" && "$BUMP" != "patch" ]]; then
    echo "Usage: $0 major|minor|patch" >&2
    exit 1
fi

REPO_ROOT="$(cd "$(dirname "$0")" && pwd)"
MOD_CPP="$REPO_ROOT/mod.cpp"
CHANGELOG="$REPO_ROOT/docs/CHANGELOG.md"

[[ -f "$MOD_CPP" ]] || { echo "ERROR: mod.cpp not found at $MOD_CPP" >&2; exit 1; }
[[ -f "$CHANGELOG" ]] || { echo "ERROR: CHANGELOG.md not found at $CHANGELOG" >&2; exit 1; }

CURRENT="$(grep -oP '(?<=^version = ")[^"]+' "$MOD_CPP" || true)"
if [[ -z "$CURRENT" ]]; then
    echo "ERROR: no line matching 'version = \"...\";' found in $MOD_CPP" >&2
    exit 1
fi

# Migrate a bare MAJOR.MINOR to full semver MAJOR.MINOR.PATCH.
IFS='.' read -ra PARTS <<< "$CURRENT"
case "${#PARTS[@]}" in
    2) MAJOR="${PARTS[0]}"; MINOR="${PARTS[1]}"; PATCH=0 ;;
    3) MAJOR="${PARTS[0]}"; MINOR="${PARTS[1]}"; PATCH="${PARTS[2]}" ;;
    *)
        echo "ERROR: unrecognized version format '$CURRENT' in $MOD_CPP (expected X.Y or X.Y.Z)" >&2
        exit 1
        ;;
esac

if ! [[ "$MAJOR" =~ ^[0-9]+$ && "$MINOR" =~ ^[0-9]+$ && "$PATCH" =~ ^[0-9]+$ ]]; then
    echo "ERROR: non-numeric version component in '$CURRENT'" >&2
    exit 1
fi

case "$BUMP" in
    major) MAJOR=$((MAJOR + 1)); MINOR=0; PATCH=0 ;;
    minor) MINOR=$((MINOR + 1)); PATCH=0 ;;
    patch) PATCH=$((PATCH + 1)) ;;
esac

NEW="$MAJOR.$MINOR.$PATCH"

echo "==> Bumping version: $CURRENT -> $NEW"
sed -i "s/^version = \"$CURRENT\";/version = \"$NEW\";/" "$MOD_CPP"
grep -qF "version = \"$NEW\";" "$MOD_CPP" || {
    echo "ERROR: failed to write new version into $MOD_CPP" >&2
    exit 1
}

if ! grep -q '^## Unreleased$' "$CHANGELOG"; then
    echo "ERROR: no '## Unreleased' heading found in $CHANGELOG" >&2
    echo "        (expected an exact line '## Unreleased')" >&2
    exit 1
fi

echo "==> Finalizing docs/CHANGELOG.md"
DATE="$(date +%Y-%m-%d)"
python3 - "$CHANGELOG" "$NEW" "$DATE" <<'PYEOF'
import sys

path, version, date = sys.argv[1:4]
with open(path) as f:
    text = f.read()

old_heading = "## Unreleased\n"
new_heading = f"## Unreleased\n\n## v{version} - {date}\n"

if text.count(old_heading) == 0:
    sys.exit("ERROR: '## Unreleased' heading not found during rewrite")

text = text.replace(old_heading, new_heading, 1)
with open(path, "w") as f:
    f.write(text)
PYEOF

echo "==> Done."
echo "$NEW"
