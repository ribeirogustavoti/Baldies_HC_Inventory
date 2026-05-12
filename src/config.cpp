class CfgPatches
{
	class Baldies_HC_Inventory
	{
		units[] = {};
        weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Belts",
			"DZ_Characters_Backpacks",
			"DZ_Characters_Vests",
			"DZ_Characters_Shoes"
		};
    };
};
class CfgMods
{
	class Baldies_HC_Inventory
	{
		dir = "Baldies_HC_Inventory";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Baldies HC Inventory";
		credits = "";
		author = "grbonis";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
	};
};
class CfgVehicles
{
	class Clothing;
	class Attack2Bag_ColorBase;
	class GulagJacket_ColorBase;
	class OMKPants_ColorBase;
	class Jeans_ColorBase: Clothing //Start of Pants.
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_Jeans_ColorBase0";
		descriptionShort="$STR_CfgVehicles_Jeans_ColorBase1";
	};
	class CargoPants_ColorBase: Clothing
	{
		itemsCargoSize[]={3,3};
		displayName = "$STR_CfgVehicles_CargoPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_CargoPants_ColorBase1";
	};
	class TTSKOPants: Clothing
	{
		scope=2;
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_TTSKOPants0";
		descriptionShort="$STR_CfgVehicles_TTSKOPants1";
	};
	class HunterPants_ColorBase: Clothing
	{
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_HunterPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_HunterPants_ColorBase1";
	};
	class CanvasPants_ColorBase: Clothing
	{
		itemsCargoSize[]={2,2};
		displayName = "$STR_CfgVehicles_CanvasPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_CanvasPants_ColorBase1";
	};
	class CanvasPantsMidi_ColorBase: Clothing
	{
		itemsCargoSize[]={2,2};
		displayName = "$STR_CfgVehicles_CanvasPantsMidi_ColorBase0";
		descriptionShort="$STR_CfgVehicles_CanvasPantsMidi_ColorBase1";
	};
	class TrackSuitPants_ColorBase: Clothing
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_TrackSuitPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_TrackSuitPants_ColorBase1";
	};
	class GorkaPants_ColorBase: Clothing
	{
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_GorkaPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_GorkaPants_ColorBase1";
	};
	class PolicePants: Clothing
	{
		scope=2;
		itemsCargoSize[]={3,3};
		displayName = "$STR_CfgVehicles_PolicePants0";
		descriptionShort="$STR_CfgVehicles_PolicePants1";
	};
	class PolicePantsOrel: Clothing
	{
		scope=2;
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_PolicePantsOrel0";
		descriptionShort="$STR_CfgVehicles_PolicePantsOrel1";
	};
	class ParamedicPants_ColorBase: Clothing
	{
		itemsCargoSize[]={3,3};
		displayName = "$STR_CfgVehicles_ParamedicPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_ParamedicPants_ColorBase1";
	};
	class FirefightersPants_ColorBase: Clothing
	{
		itemsCargoSize[]={3,3};
		displayName = "$STR_CfgVehicles_FirefightersPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_FirefightersPants_ColorBase1";
	};
	class PrisonUniformPants: Clothing
	{
		scope=2;
		itemsCargoSize[]={2,2};
		displayName = "$STR_CfgVehicles_PrisonUniformPants0";
		descriptionShort="$STR_CfgVehicles_PrisonUniformPants1";
	};
	class MedicalScrubsPants_ColorBase: Clothing
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_MedicalScrubsPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_MedicalScrubsPants_ColorBase1";
	};
	class USMCPants_ColorBase: Clothing
	{
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_USMCPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_USMCPants_ColorBase1";
	};
	class SlacksPants_ColorBase: Clothing
	{
		scope=0;
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_SlacksPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_SlacksPants_ColorBase1";
	};
	class BDUPants: Clothing
	{
		scope=2;
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_BDUPants0";
		descriptionShort="$STR_CfgVehicles_BDUPants1";
	};
	class NBCPantsBase: Clothing
	{
		scope=0;
		itemsCargoSize[]={0,0};
		displayName = "$STR_CfgVehicles_NBCPantsBase0";
		descriptionShort="$STR_CfgVehicles_NBCPantsBase1";
	};
	class Breeches_ColorBase: Clothing
	{
		scope=0;
		itemsCargoSize[]={2,2};
		displayName = "$STR_CfgVehicles_Breeches_ColorBase0";
		descriptionShort="$STR_CfgVehicles_Breeches_ColorBase1";
	};
	class ShortJeans_ColorBase: Clothing
	{
		scope=0;
		itemsCargoSize[]={2,2};
		displayName = "$STR_CfgVehicles_ShortJeans_ColorBase0";
		descriptionShort="$STR_CfgVehicles_ShortJeans_ColorBase1";
	};
	class Skirt_ColorBase: Clothing
	{
		scope=0;
		itemsCargoSize[]={2,2};
		displayName = "$STR_CfgVehicles_Skirt_ColorBase0";
		descriptionShort="$STR_CfgVehicles_Skirt_ColorBase1";
	};
	class JumpsuitPants_ColorBase: Clothing
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_JumpsuitPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_JumpsuitPants_ColorBase1";
	};
	class LegsCover_Improvised: Clothing
	{
		scope=2;
		itemsCargoSize[]={0,0};
		displayName = "$STR_LegsCover_Improvised0";
		descriptionShort="$STR_LegsCover_Improvised1";
	};
	class Chainmail_Leggings: Clothing
	{
		scope=2;
		itemsCargoSize[]={0,0};
		displayName = "$STR_CfgVehicles_Chainmail_Leggings0";
		descriptionShort="$STR_CfgVehicles_Chainmail_Leggings1";
	};
	class Sweater_ColorBase: Clothing // Start of Tops.
	{
		itemsCargoSize[]={0,0};
		displayName = "$STR_CfgVehicles_Sweater_ColorBase0";
		descriptionShort="$STR_CfgVehicles_Sweater_ColorBase1";
	};
	class Shirt_ColorBase: Clothing
	{
		itemsCargoSize[]={1,1};
		displayName = "$STR_CfgVehicles_Shirt_ColorBase0";
		descriptionShort="$STR_CfgVehicles_Shirt_ColorBase1";
	};
	class TShirt_ColorBase: Clothing
	{
		itemsCargoSize[]={0,0};
		displayName = "$STR_CfgVehicles_TShirt_ColorBase0";
		descriptionShort="$STR_CfgVehicles_TShirt_ColorBase1";
	};
	class Hoodie_ColorBase: Clothing
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_Hoodie_ColorBase0";
		descriptionShort="$STR_CfgVehicles_Hoodie_ColorBase1";
	};
	class TacticalShirt_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_TacticalShirt_ColorBase0";
		descriptionShort="$STR_CfgVehicles_TacticalShirt_ColorBase1";
	};
	class DownJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName="$STR_cfgvehicles_bubblegoose_colorbase0";
		descriptionShort="$STR_cfgvehicles_bubblegoose_colorbase1";
	};
	class HikingJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_HikingJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_HikingJacket_ColorBase1";
	};
	class Raincoat_ColorBase: Clothing
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_Raincoat_ColorBase0";
		descriptionShort="$STR_CfgVehicles_Raincoat_ColorBase1";
	};
	class TorsoCover_Improvised: Clothing
	{
		scope=2;
		itemsCargoSize[]={0,0};
		displayName = "$STR_TorsoCover_Improvised0";
		descriptionShort="$STR_TorsoCover_Improvised1";
	};
	class M65Jacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_M65Jacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_M65Jacket_ColorBase1";
	};
	class TTsKOJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_TTsKOJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_TTsKOJacket_ColorBase1";
	};
	class GorkaEJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_GorkaEJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_GorkaEJacket_ColorBase1";
	};
	class RidersJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={3,3};
		displayName = "$STR_CfgVehicles_RidersJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_RidersJacket_ColorBase1";
	};
	class WoolCoat_ColorBase: Clothing
	{
		itemsCargoSize[]={3,3};
		displayName = "$STR_CfgVehicles_WoolCoat_ColorBase0";
		descriptionShort="$STR_CfgVehicles_WoolCoat_ColorBase1";
	};
	class TrackSuitJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={3,3};
		displayName = "$STR_CfgVehicles_TrackSuitJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_TrackSuitJacket_ColorBase1";
	};
	class BushlatPoliceJacket_ColorBase: Clothing
	{
		scope=2;
		itemsCargoSize[]={5,3};
		displayName="$STR_CfgVehicles_BushlatPoliceJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_BushlatPoliceJacket_ColorBase1";
	};
	class PoliceJacket: Clothing
	{
		scope=2;
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_PoliceJacket0";
		descriptionShort="$STR_CfgVehicles_PoliceJacket1";
	};
	class PoliceJacketOrel: Clothing
	{
		scope=2;
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_PoliceJacketOrel0";
		descriptionShort="$STR_CfgVehicles_PoliceJacketOrel1";
	};
	class ParamedicJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_ParamedicJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_ParamedicJacket_ColorBase1";
	};
	class FirefighterJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_FirefighterJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_FirefighterJacket_ColorBase1";
	};
	class PrisonUniformJacket: Clothing
	{
		scope=2;
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_PrisonUniformJacket0";
		descriptionShort="$STR_CfgVehicles_PrisonUniformJacket1";
	};
	class MiniDress_ColorBase: Clothing
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_MiniDress_ColorBase0";
		descriptionShort="$STR_CfgVehicles_MiniDress_ColorBase1";
	};
	class QuiltedJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_QuiltedJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_QuiltedJacket_ColorBase1";
	};
	class BomberJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_BomberJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_BomberJacket_ColorBase1";
	};
	class HuntingJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_HuntingJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_HuntingJacket_ColorBase1";
	};
	class MedicalScrubsShirt_ColorBase: Clothing
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_MedicalScrubsShirt_ColorBase0";
		descriptionShort="$STR_CfgVehicles_MedicalScrubsShirt_ColorBase1";
	};
	class LabCoat: Clothing
	{
		scope=2;
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_LabCoat0";
		descriptionShort="$STR_CfgVehicles_LabCoat1";
	};
	class NurseDress_ColorBase: Clothing
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_NurseDress_ColorBase0";
		descriptionShort="$STR_CfgVehicles_NurseDress_ColorBase1";
	};
	class USMCJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_USMCJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_USMCJacket_ColorBase1";
	};
	class OMKJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName="$STR_CfgVehicles_OMKJacket_ColorBase0";
		descriptionShort="$STR_cfgvehicles_OMKJacket_Colorbase1";
	};
	class Blouse_ColorBase: Clothing
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_Blouse_ColorBase0";
		descriptionShort="$STR_CfgVehicles_Blouse_ColorBase1";
	};
	class NBCJacketBase: Clothing
	{
		scope=0;
		itemsCargoSize[]={0,0};
		displayName = "$STR_CfgVehicles_NBCJacketBase0";
		descriptionShort="$STR_CfgVehicles_NBCJacketBase1";
	};
	class DenimJacket: Clothing
	{
		scope=2;
		itemsCargoSize[]={3,4};
		displayName = "$STR_CfgVehicles_DenimJacket0";
		descriptionShort="$STR_CfgVehicles_DenimJacket1";
	};
	class TelnyashkaShirt: Clothing
	{
		scope=2;
		itemsCargoSize[]={0,0};
		displayName = "$STR_cfgvehicles_telnyashkashirt0";
		descriptionShort="$STR_cfgvehicles_telnyashkashirt1";
	};
	class ChernarusSportShirt: Clothing
	{
		scope=2;
		itemsCargoSize[]={0,0};
		displayName = "$STR_CfgVehicles_ChernarusSportShirt0";
		descriptionShort="$STR_CfgVehicles_ChernarusSportShirt1";
	};
	class JumpsuitJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_JumpsuitJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_JumpsuitJacket_ColorBase1";
	};
	class BDUJacket: Clothing
	{
		scope=2;
		itemsCargoSize[]={5,3};
		displayName = "$STR_CfgVehicles_BDUJacket0";
		descriptionShort="$STR_CfgVehicles_BDUJacket1";
	};
	class ManSuit_ColorBase: Clothing
	{
		itemsCargoSize[]={3,3};
		displayName = "$STR_CfgVehicles_ManSuit_ColorBase0";
		descriptionShort="$STR_CfgVehicles_ManSuit_ColorBase1";
	};
	class WomanSuit_ColorBase: Clothing
	{
		itemsCargoSize[]={3,3};
		displayName = "$STR_CfgVehicles_WomanSuit_ColorBase0";
		descriptionShort="$STR_CfgVehicles_WomanSuit_ColorBase1";
	};
	class LeatherJacket_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName="$STR_CfgVehicles_LeatherJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_LeatherJacket_ColorBase1";
	};
	class LeatherShirt_ColorBase: Clothing
	{
		itemsCargoSize[]={0,0};
		displayName="$STR_CfgVehicles_LeatherShirt_ColorBase0";
		descriptionShort="$STR_CfgVehicles_LeatherShirt_ColorBase1";
	};
	class Chainmail: Clothing
	{
		scope=2;
		itemsCargoSize[]={0,0};
		displayName = "$STR_CfgVehicles_Chainmail0";
		descriptionShort="$STR_CfgVehicles_Chainmail1";
	};
	class TaloonBag_ColorBase: Clothing //Start of Bags
	{
		itemsCargoSize[]={4,5};
		displayName = "$STR_cfgVehicles_TaloonBag_ColorBase0";
		descriptionShort="$STR_cfgVehicles_TaloonBag_ColorBase1";
	};
	class TortillaBag: Clothing //Combat_Bag
	{
		scope=2;
		itemsCargoSize[]={5,5};
		displayName = "$STR_cfgVehicles_TortillaBag0";
		descriptionShort="$STR_cfgVehicles_TortillaBag1";
	};
	class CourierBag: Clothing
	{
		scope=2;
		itemsCargoSize[]={3,4};
		displayName = "$STR_cfgVehicles_CourierBag0";
		descriptionShort="$STR_cfgVehicles_CourierBag1";
	};
	class FurCourierBag: Clothing
	{
		scope=2;
		itemsCargoSize[]={3,4};
		displayName = "$STR_cfgVehicles_FurCourierBag0";
		descriptionShort="$STR_cfgVehicles_FurCourierBag1";
	};
	class LeatherSack_ColorBase: Clothing
	{
		scope=2;
		itemsCargoSize[]={5,4};
		displayName="$STR_cfgVehicles_LeatherSack_ColorBase0";
		descriptionShort="$STR_cfgVehicles_LeatherSack_ColorBase1";
	};
	class ImprovisedBag: Clothing
	{
		scope=2;
		itemsCargoSize[]={3,5};
		displayName = "$STR_cfgVehicles_ImprovisedBag0";
		descriptionShort="$STR_cfgVehicles_ImprovisedBag1";
	};
	class FurImprovisedBag: Clothing
	{
		scope=2;
		itemsCargoSize[]={3,5};
		displayName = "$STR_cfgVehicles_FurImprovisedBag0";
		descriptionShort="$STR_cfgVehicles_FurImprovisedBag1";
	};
	class DryBag_ColorBase: Clothing
	{
		itemsCargoSize[]={4,7};
		displayName = "$STR_cfgVehicles_DryBag_ColorBase0";
		descriptionShort="$STR_cfgVehicles_DryBag_ColorBase1";
	};
	class HuntingBag: Clothing
	{
		scope=2;
		itemsCargoSize[]={5,5};
		displayName = "$STR_cfgVehicles_HuntingBag0";
		descriptionShort="$STR_cfgVehicles_HuntingBag1";
	};
	class MountainBag_ColorBase: Clothing
	{
		itemsCargoSize[]={4,7};
		displayName = "$STR_cfgVehicles_MountainBag_ColorBase0";
		descriptionShort="$STR_cfgVehicles_MountainBag_ColorBase1";
	};
	class SmershBag: Clothing
	{
		scope=2;
		itemsCargoSize[]={4,3};
		displayName = "$STR_cfgVehicles_SmershBag0";
		descriptionShort="$STR_cfgVehicles_SmershBag1";
	};
	class ChildBag_ColorBase: Clothing //School_Backpack
	{
		itemsCargoSize[]={5,4};
		displayName = "$STR_cfgVehicles_ChildBag_ColorBase0";
		descriptionShort="$STR_cfgVehicles_ChildBag_ColorBase1";
	};
	class AssaultBag_ColorBase: Clothing
	{
		itemsCargoSize[]={6,5};
		displayName = "$STR_cfgVehicles_AssaultBag_ColorBase0";
		descriptionShort="$STR_cfgVehicles_AssaultBag_ColorBase1";
	};
	class CoyoteBag_ColorBase: Clothing
	{
		itemsCargoSize[]={7,7};
		displayName = "$STR_cfgVehicles_CoyoteBag_ColorBase0";
		descriptionShort="$STR_cfgVehicles_CoyoteBag_ColorBase1";
	};
	class AliceBag_ColorBase: Clothing
	{
		itemsCargoSize[]={7,7};
		displayName = "$STR_cfgVehicles_AliceBag_ColorBase0";
		descriptionShort="$STR_cfgVehicles_AliceBag_ColorBase1";
	};
	class SlingBag_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_cfgvehicles_Slingbag0";
		descriptionShort="$STR_cfgvehicles_Slingbag1";
	};
	class ArmyPouch_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_cfgvehicles_ArmyPouch_ColorBase0";
		descriptionShort="$STR_cfgvehicles_ArmyPouch_ColorBase1";
	};
	class DuffelBagSmall_ColorBase: Clothing
	{
		itemsCargoSize[]={5,3};
		displayName = "$STR_cfgvehicles_DuffelBagSmall_ColorBase0";
		descriptionShort="$STR_cfgvehicles_DuffelBagSmall_ColorBase1";
	};
	class CanvasBag_ColorBase: Clothing
	{
		itemsCargoSize[]={4,5};
		displayName = "$STR_cfgvehicles_CanvasBag_ColorBase0";
		descriptionShort="$STR_cfgvehicles_CanvasBag_ColorBase1";
	};
	class HipPack_ColorBase: Clothing // Belts
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_cfgvehicles_HipPack_ColorBase0";
		descriptionShort="$STR_cfgvehicles_HipPack_ColorBase1";
	};
	class SmershVest: Clothing // Start of Vests
	{
		scope=2;
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_SmershVest0";
		descriptionShort="$STR_CfgVehicles_SmershVest1";
	};
	class PressVest_ColorBase: Clothing
	{
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_PressVest_ColorBase0";
		descriptionShort="$STR_CfgVehicles_PressVest_ColorBase1";
	};
	class UKAssVest_ColorBase: Clothing
	{
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_UKAssVest_ColorBase0";
		descriptionShort="$STR_CfgVehicles_UKAssVest_ColorBase1";
	};
	class HighCapacityVest_ColorBase: Clothing
	{
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_HighCapacityVest_ColorBase0";
		descriptionShort="$STR_CfgVehicles_HighCapacityVest_ColorBase1";
	};
	class LeatherStorageVest_ColorBase: Clothing
	{
		itemsCargoSize[]={3,3};
		displayName="$STR_CfgVehicles_LeatherStorageVest_ColorBase0";
		descriptionShort="$STR_CfgVehicles_LeatherStorageVest_ColorBase1";
	};
	class HuntingVest: Clothing
	{
		scope=2;
		itemsCargoSize[]={4,3};
		displayName = "$STR_CfgVehicles_HuntingVest0";
		descriptionShort="$STR_CfgVehicles_HuntingVest1";
	};
	class AthleticShoes_ColorBase: Clothing // Start of Footwear
	{
		itemsCargoSize[]={0,0};
		displayName = "$STR_CfgVehicles_AthleticShoes_ColorBase0";
		descriptionShort="$STR_CfgVehicles_AthleticShoes_ColorBase1";
	};
	class HikingBoots_ColorBase: Clothing
	{
		itemsCargoSize[]={0,0};
		displayName = "$STR_CfgVehicles_HikingBoots_ColorBase0";
		descriptionShort="$STR_CfgVehicles_HikingBoots_ColorBase1";
	};
	class Attack2Bag_Black: Attack2Bag_ColorBase //Start of Attack2Bag family (no ColorBase in base game).
	{
		scope=2;
		itemsCargoSize[]={8,7};
	};
	class Attack2Bag_Green: Attack2Bag_ColorBase
	{
		scope=2;
		itemsCargoSize[]={8,7};
	};
	class Attack2Bag_Ttsko: Attack2Bag_ColorBase
	{
		scope=2;
		itemsCargoSize[]={8,7};
	};
	class Attack2Bag_Yeger: Attack2Bag_ColorBase
	{
		scope=2;
		itemsCargoSize[]={8,7};
	};
	class DrysackBag_ColorBase: Clothing
	{
		itemsCargoSize[]={4,4};
		displayName = "$STR_CfgVehicles_DrysackBag_ColorBase0";
		descriptionShort="$STR_CfgVehicles_DrysackBag_ColorBase1";
	};
	class WaterproofBag_ColorBase: Clothing
	{
		itemsCargoSize[]={4,4};
		displayName = "$STR_CfgVehicles_WaterproofBag_ColorBase0";
		descriptionShort="$STR_CfgVehicles_WaterproofBag_ColorBase1";
	};
	class HuntingBag_Hannah: HuntingBag
	{
		scope=2;
		itemsCargoSize[]={5,5};
	};
	class TortillaBag_Winter: TortillaBag
	{
		scope=2;
		itemsCargoSize[]={4,4};
	};
	class ReflexVest: Clothing
	{
		scope=2;
		itemsCargoSize[]={0,0};
	};
	class HuntingVest_Winter: HuntingVest
	{
		itemsCargoSize[]={4,3};
	};
	class PilotJacket_ColorBase: Clothing //Start of additional Jackets/Coats.
	{
		itemsCargoSize[]={3,3};
		displayName = "$STR_CfgVehicles_PilotJacket_ColorBase0";
		descriptionShort="$STR_CfgVehicles_PilotJacket_ColorBase1";
	};
	class WinterMilitaryCoat_ColorBase: Clothing
	{
		itemsCargoSize[]={5,5};
		displayName = "$STR_CfgVehicles_WinterMilitaryCoat_ColorBase0";
		descriptionShort="$STR_CfgVehicles_WinterMilitaryCoat_ColorBase1";
	};
	class GulagJacket_Grey: GulagJacket_ColorBase
	{
		scope=2;
		itemsCargoSize[]={2,2};
	};
	class NavyUniformJacket: WoolCoat_ColorBase
	{
		scope=2;
		itemsCargoSize[]={3,3};
	};
	class MilitarySweater_ColorBase: Clothing //Start of additional Shirts/Sweaters.
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_MilitarySweater_ColorBase0";
		descriptionShort="$STR_CfgVehicles_MilitarySweater_ColorBase1";
	};
	class LeatherPants_ColorBase: Clothing //Start of additional Pants.
	{
		itemsCargoSize[]={3,2};
		displayName = "$STR_CfgVehicles_LeatherPants_ColorBase0";
		descriptionShort="$STR_CfgVehicles_LeatherPants_ColorBase1";
	};
	class OMKPants_Navy: OMKPants_ColorBase
	{
		itemsCargoSize[]={4,3};
		//displayName="$STR_CfgVehicles_OMKPants_ColorBase0";
		//descriptionShort="$STR_CfgVehicles_OMKPants_ColorBase1";
	};
	class NavyUniformPants: PolicePants
	{
		scope=2;
		itemsCargoSize[]={3,2};
	};
	class Chainmail_Coif: Clothing //Start of Coifs/Hoods (no cargo).
	{
		scope=2;
		itemsCargoSize[]={0,0};
	};
	class WinterCoif_ColorBase: Clothing
	{
		itemsCargoSize[]={0,0};
		displayName = "$STR_CfgVehicles_WinterCoif_ColorBase0";
		descriptionShort="$STR_CfgVehicles_WinterCoif_ColorBase1";
	};
	class WitchHoodCoif_ColorBase: Clothing
	{
		itemsCargoSize[]={0,0};
		displayName = "$STR_CfgVehicles_WitchHoodCoif_ColorBase0";
		descriptionShort="$STR_CfgVehicles_WitchHoodCoif_ColorBase1";
	};
	class PlateCarrierPouches: Clothing //Start of plate pouches.
	{
		itemsCargoSize[]={3,3};
	};
};
