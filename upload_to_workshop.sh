#!/usr/bin/env bash
# Publish (or update) this mod's Steam Workshop item.
#
# Identical across all Baldies_* mod repos — never hardcodes a mod name,
# only ever reads/writes files relative to its own location (the repo root).
#
# Usage:
#   ./upload_to_workshop.sh
#
# Requires, in order:
#   1. build/@<ModName>/ already built via ./build.sh (this script does NOT
#      build for you — it fails if the build is missing or stale).
#   2. A shared username file at ~/Games/dayz_mods/secrets/steam_workshop.env
#      containing a line: STEAM_USER=<your steam username>
#   3. That username's password stored in the GNOME Keyring, set up once via:
#        secret-tool store --label="DayZ Workshop (dayz_mods)" \
#            service dayz-mods-steam-workshop username <STEAM_USER>
#
# The account has Steam Guard (mobile authenticator) enabled, so steamcmd's
# login step is ALWAYS interactive — you must be present at the terminal to
# type the current Guard code when prompted. This script cannot run
# unattended/from cron.
#
# NOTE on exposure: steamcmd only accepts the password as a command-line
# argument (`+login user pass`), which is visible to other local processes
# on this machine via /proc/<pid>/cmdline while steamcmd is running. On a
# single-user machine this is a low but real exposure window — flagging it
# here rather than hiding it.
#
# NOTE on feasibility: whether DayZ's Workshop backend accepts uploads via
# steamcmd's workshop_build_item at all (vs. requiring Bohemia's own
# Windows-only Publisher tool) is UNCONFIRMED. The first real run of this
# script is the actual test of that.

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")" && pwd)"
MOD_NAME="$(basename "$REPO_ROOT")"
CONTENT_DIR="$REPO_ROOT/build/@${MOD_NAME}"
PBO="$CONTENT_DIR/addons/${MOD_NAME}.pbo"
ID_FILE="$REPO_ROOT/workshop_id.txt"
VDF_PATH="$REPO_ROOT/workshop.vdf"
SHARED_ENV="$HOME/Games/dayz_mods/secrets/steam_workshop.env"
KEYRING_SERVICE="dayz-mods-steam-workshop"

# ---- 1. build present ------------------------------------------------------

if [[ ! -f "$PBO" ]]; then
    echo "ERROR: no built .pbo found at $PBO" >&2
    echo "        Run ./build.sh first." >&2
    exit 1
fi

# ---- 2. staleness check -----------------------------------------------------

STALE="$(find "$REPO_ROOT/src" "$REPO_ROOT/mod.cpp" "$REPO_ROOT/keys" -newer "$PBO" 2>/dev/null || true)"
if [[ -n "$STALE" ]]; then
    echo "ERROR: source is newer than the built .pbo — rebuild first (./build.sh):" >&2
    echo "$STALE" >&2
    exit 1
fi

# ---- 3. credentials ----------------------------------------------------------

if [[ ! -f "$SHARED_ENV" ]]; then
    echo "ERROR: shared config not found at $SHARED_ENV" >&2
    echo "        Create it with a single line: STEAM_USER=<your steam username>" >&2
    exit 1
fi
STEAM_USER="$(grep -m1 '^STEAM_USER=' "$SHARED_ENV" | cut -d= -f2- || true)"
if [[ -z "$STEAM_USER" ]]; then
    echo "ERROR: STEAM_USER not set in $SHARED_ENV" >&2
    exit 1
fi

command -v secret-tool >/dev/null 2>&1 || {
    echo "ERROR: secret-tool not found on PATH" >&2
    exit 1
}
if ! STEAM_PASSWORD="$(secret-tool lookup service "$KEYRING_SERVICE" username "$STEAM_USER")" || [[ -z "$STEAM_PASSWORD" ]]; then
    echo "ERROR: no keyring entry for service=$KEYRING_SERVICE username=$STEAM_USER" >&2
    echo "        Set it up once with:" >&2
    echo "        secret-tool store --label=\"DayZ Workshop (dayz_mods)\" service $KEYRING_SERVICE username $STEAM_USER" >&2
    exit 1
fi

# ---- 4. regenerate the vdf ---------------------------------------------------

"$REPO_ROOT/create_vdf.sh"

PRE_ID="0"
if [[ -f "$ID_FILE" ]]; then
    PRE_ID="$(tr -d '[:space:]' < "$ID_FILE")"
    [[ -z "$PRE_ID" ]] && PRE_ID="0"
fi

# ---- 5. upload ----------------------------------------------------------------

echo "==> Running steamcmd. Steam Guard will prompt for a live code — watch this terminal."
set +e
steamcmd +login "$STEAM_USER" "$STEAM_PASSWORD" +workshop_build_item "$VDF_PATH" +quit
STEAMCMD_RC=$?
set -e
unset STEAM_PASSWORD

if [[ $STEAMCMD_RC -ne 0 ]]; then
    echo "ERROR: steamcmd exited with status $STEAMCMD_RC — see its output above." >&2
    exit 1
fi

# ---- 6. record the publishedfileid ---------------------------------------------

echo
if [[ "$PRE_ID" == "0" ]]; then
    echo "This was a NEW item. steamcmd's output above should show its publishedfileid / Workshop URL."
    read -rp "Paste the new publishedfileid (digits only) to save into workshop_id.txt: " NEW_ID
    if ! [[ "$NEW_ID" =~ ^[0-9]+$ ]]; then
        echo "ERROR: '$NEW_ID' isn't numeric — NOT writing workshop_id.txt." >&2
        echo "        Re-run this script once you have the correct ID, or edit workshop_id.txt by hand." >&2
        exit 1
    fi
    echo "$NEW_ID" > "$ID_FILE"
    echo "==> Saved publishedfileid $NEW_ID to $ID_FILE"
    echo "    https://steamcommunity.com/sharedfiles/filedetails/?id=$NEW_ID"
else
    echo "==> Updated existing Workshop item $PRE_ID"
    echo "    https://steamcommunity.com/sharedfiles/filedetails/?id=$PRE_ID"
fi
