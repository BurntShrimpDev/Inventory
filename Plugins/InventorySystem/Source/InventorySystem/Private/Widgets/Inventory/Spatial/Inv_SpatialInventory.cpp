// Copyright Callum Brogan.


#include "Widgets/Inventory/Spatial/Inv_SpatialInventory.h"

#include "InventorySystem.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "InventoryManagement/Utils/Inv_InventoryStatics.h"
#include "InventorySystem.h"
#include "Widgets/Inventory/Spatial/Inv_InventoryGrid.h"

void UInv_SpatialInventory::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	Button_Equipment->OnClicked.AddDynamic(this, &ThisClass::ShowEquipment);
	Button_Consumables->OnClicked.AddDynamic(this, &ThisClass::ShowConsumables);
	Button_Crafting->OnClicked.AddDynamic(this, &ThisClass::ShowCrafting);

	ShowEquipment();
}

FInv_SlotAvailabilityResult UInv_SpatialInventory::HasRoomForItem(UInv_ItemComponent* ItemComponent) const
{
	switch (UInv_InventoryStatics::GetItemCategoryFromItemComp(ItemComponent))
	{
	case EInv_ItemCategory::Equipment:
		return Grid_Equipment->HasRoomForItem(ItemComponent);
	case EInv_ItemCategory::Consumable:
		return Grid_Consumables->HasRoomForItem(ItemComponent);
	case EInv_ItemCategory::Crafting:
		return Grid_Crafting->HasRoomForItem(ItemComponent);
		default:
		UE_LOG(LogInventory, Error, TEXT("ItemComponent doesn't have a valid Item Category"))
		return FInv_SlotAvailabilityResult();
	}
}

void UInv_SpatialInventory::ShowEquipment()
{
	SetActiveGrid(Grid_Equipment, Button_Equipment);
}

void UInv_SpatialInventory::ShowConsumables()
{
	SetActiveGrid(Grid_Consumables, Button_Consumables);
}

void UInv_SpatialInventory::ShowCrafting()
{
	SetActiveGrid(Grid_Crafting, Button_Crafting);
}

void UInv_SpatialInventory::DisableButton(UButton* Button)
{
	Button_Equipment->SetIsEnabled(true);
	Button_Consumables->SetIsEnabled(true);
	Button_Crafting->SetIsEnabled(true);
	Button->SetIsEnabled(false);
}

void UInv_SpatialInventory::SetActiveGrid(UInv_InventoryGrid* InventoryGrid, UButton* Button)
{
	DisableButton(Button);

	Switcher->SetActiveWidget(InventoryGrid);
}
