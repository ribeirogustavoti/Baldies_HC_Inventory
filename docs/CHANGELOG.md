# Changelog

## Unreleased

## v1.0.2 - 2026-09-14

- Fix `PlateCarrierPouches` and `WaterproofBag_ColorBase` using the wrong
  base class. Both overrides were declared `: Clothing`, but vanilla defines
  them as `: Container_Base` in `gear_containers.pbo`. The mismatch made the
  server log `Type '<class>' must be inherited from class 'Clothing_Base'`
  errors for these classes and their color variants.
  Fixes:
  - Base changed to `Container_Base` on both classes (matches vanilla).
    Cargo sizes are unchanged.
  - Added `class Container_Base;` forward declaration next to the existing
    `class Clothing;` at the top of CfgVehicles.
  - Added `DZ_Gear_Containers` to `requiredAddons[]` so the mod loads after
    the vanilla file that owns both classes.
  - `CfgMods` `version` in `config.cpp` set to match `mod.cpp`.

## v1.0.1 - 2026-08-04

- Initial repo import. Forked scope from upstream Realistic_Inventory mod;
  added cargo overrides for 29 additional classes covering Attack2Bag,
  PlateCarrierVest, DrysackBag, WaterproofBag, WinterMilitaryCoat, PilotJacket,
  LeatherPants, MilitarySweater, and other newer Chernarus/Livonia/Sakhal
  items not covered upstream.
