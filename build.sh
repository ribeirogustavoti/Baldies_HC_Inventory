#!/usr/bin/env bash
# Build and sign the Baldies_HC_Inventory PBO.
#
# Usage:  ./build.sh
# Override the private key path with:
#   BHC_PRIVKEY=/path/to/key.biprivatekey ./build.sh
set -euo pipefail

MOD_NAME="Baldies_HC_Inventory"
PRIVKEY="${BHC_PRIVKEY:-$HOME/Games/dayz_mods/baldies_hc.biprivatekey}"

REPO_ROOT="$(cd "$(dirname "$0")" && pwd)"
BUILD_DIR="$REPO_ROOT/build"
MOD_DIR="$BUILD_DIR/@${MOD_NAME}"

if [[ ! -f "$PRIVKEY" ]]; then
    echo "ERROR: private key not found at $PRIVKEY" >&2
    echo "Set BHC_PRIVKEY=/path/to/key.biprivatekey to override." >&2
    exit 1
fi

command -v armake >/dev/null 2>&1 || {
    echo "ERROR: armake not found on PATH" >&2
    exit 1
}

echo "==> Preparing build directory"
rm -rf "$BUILD_DIR"
mkdir -p "$MOD_DIR/addons" "$MOD_DIR/keys"

echo "==> Staging src/ as $MOD_NAME/"
# armake uses the source dir name as the PBO prefix by default, and
# $PBOPREFIX$ inside it takes precedence. Naming the staging folder to match
# the mod guarantees the prefix is correct either way.
cp -r "$REPO_ROOT/src" "$BUILD_DIR/$MOD_NAME"

echo "==> Copying mod-root metadata and public key"
cp "$REPO_ROOT/mod.cpp"       "$MOD_DIR/"
cp "$REPO_ROOT/keys/"*.bikey  "$MOD_DIR/keys/"

echo "==> Packing PBO (script-only mod, no binarization)"
armake build -f -p \
    -x "*.git*" -x "*.md" -x "*.bak" \
    "$BUILD_DIR/$MOD_NAME/" \
    "$MOD_DIR/addons/${MOD_NAME}.pbo"

echo "==> Signing PBO"
armake sign -f "$PRIVKEY" "$MOD_DIR/addons/${MOD_NAME}.pbo"

echo "==> Verifying packed PBO"
armake inspect "$MOD_DIR/addons/${MOD_NAME}.pbo" | head -5

echo ""
echo "Build complete: $MOD_DIR"
echo ""
echo "To deploy:"
echo "  SERVER=~/.local/share/Steam/steamapps/common/DayZServer"
echo "  rm -rf \"\$SERVER/@${MOD_NAME}\""
echo "  cp -r \"$MOD_DIR\" \"\$SERVER/\""
echo "  cp \"$REPO_ROOT/keys/\"*.bikey \"\$SERVER/keys/\""
