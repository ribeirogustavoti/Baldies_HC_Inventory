# Changelog

## Unreleased

## v1.0.2 - 2026-09-14

- Fix plate carrier pouches refusing new items while attached to the plate.
  Root cause: the mod's `PlateCarrierPouches` override at `src/config.cpp:754`
  used `: Clothing` as its base, but vanilla defines the class as
  `PlateCarrierPouches : Container_Base` in `gear_containers.pbo`. The
  base-class mismatch dropped the vanilla `allowOwnedCargoManipulation = 1`
  flag, which is what lets a wearer add cargo to an attached container.
  Fixes:
  - Base changed to `Container_Base` (matches vanilla + the pattern used by
    Treee's iat_universal_dye/dz_config_overrides mods when overriding the
    same class).
  - `allowOwnedCargoManipulation = 1;` set explicitly on the override so
    the flag is guaranteed regardless of Enfusion's merge behavior.
  - Added `class Container_Base;` forward declaration next to the existing
    `class Clothing;` at the top of CfgVehicles.
  - Added `DZ_Gear_Containers` to `requiredAddons[]` so the mod loads after
    the vanilla file that owns `PlateCarrierPouches`.

## v1.0.1 - 2026-08-04

- Initial repo import. Forked scope from upstream Realistic_Inventory mod;
  added cargo overrides for 29 additional classes covering Attack2Bag,
  PlateCarrierVest, DrysackBag, WaterproofBag, WinterMilitaryCoat, PilotJacket,
  LeatherPants, MilitarySweater, and other newer Chernarus/Livonia/Sakhal
  items not covered upstream.
