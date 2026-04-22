# Baldies_HC_Inventory

Hardcore DayZ inventory mod. Overrides `itemsCargoSize[]` on clothing, bags,
and vests across Chernarus, Livonia, and Sakhal to give every container a
realistic internal storage grid.

## Prerequisites

- [armake](https://github.com/KoffeinFlummi/armake) on `PATH`
- A signing keypair (generate with `armake keygen`)

## First-time setup

```bash
# Generate your own signing keypair and install the public half
armake keygen -f ~/baldies_hc
chmod 600 ~/baldies_hc.biprivatekey
cp ~/baldies_hc.bikey keys/
```

## Build

```bash
BHC_PRIVKEY=~/baldies_hc.biprivatekey ./build.sh
```

Output: `build/@Baldies_HC_Inventory/` — a ready-to-deploy mod folder.

## Deploy to a local DayZ server

```bash
SERVER=~/.local/share/Steam/steamapps/common/DayZServer
rm -rf "$SERVER/@Baldies_HC_Inventory"
cp -r build/@Baldies_HC_Inventory "$SERVER/"
cp keys/*.bikey "$SERVER/keys/"
```

Add `@Baldies_HC_Inventory` to the `-mod=` launch parameter and set
`verifySignatures = 2;` in `serverDZ.cfg`.
