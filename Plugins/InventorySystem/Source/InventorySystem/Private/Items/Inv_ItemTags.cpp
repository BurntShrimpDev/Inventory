#include "Items/Inv_ItemTags.h"

namespace GameItems
{
	namespace Equipment
	{
		namespace Weapons
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Axe, "GameItems.Equipment.Weapons.Axe", "Axe")
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(Sword, "GameItems.Equipment.Weapons.Sword", "Sword")
		}

		namespace Cloaks
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(RedCloak, "GameItems.Equipment.Cloaks.RedCloak", "RedCloak")
		}

		namespace Masks
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(SteelMask, "GameItems.Equipment.Masks.SteelMask", "SteelMask")
		}
	}

	namespace Consumables
	{
		namespace Potions
		{
			namespace Red
			{
				UE_DEFINE_GAMEPLAY_TAG_COMMENT(Small, "GameItems.Consumables.Potion.Red.Small", "Small Red Potion")
				UE_DEFINE_GAMEPLAY_TAG_COMMENT(Large, "GameItems.Consumables.Potion.Red.Large", "Large Red Potion")
			}

			namespace Blue
			{
				UE_DEFINE_GAMEPLAY_TAG_COMMENT(Small, "GameItems.Consumables.Potion.Blue.Small", "Small Blue Potion")
				UE_DEFINE_GAMEPLAY_TAG_COMMENT(Large, "GameItems.Consumables.Potion.Blue.Large", "Large Blue Potion")
			}
		}
	}

	namespace Crafting
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(FireFernFruit, "GameItems.Crafting.FireFernFruit", "FireFernFruit")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(LuminDaisy, "GameItems.Crafting.LuminDaisy", "LuminDaisy")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ScorchPetalBlossom, "GameItems.Crafting.ScorchPetalBlossom", "ScorchPetalBlossom")
	}
}
