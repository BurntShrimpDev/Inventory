// Copyright Callum Brogan.


#include "Widgets/Inventory/Spatial/Inv_SpatialInventory.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
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
	return FInv_SlotAvailabilityResult();
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
