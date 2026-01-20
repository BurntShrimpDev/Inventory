// Copyright Callum Brogan.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Inventory/InventoryBase/Inv_InventoryBase.h"
#include "Inv_SpatialInventory.generated.h"

class UButton;
class UWidgetSwitcher;
class UInv_InventoryGrid;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInv_SpatialInventory : public UInv_InventoryBase
{
	GENERATED_BODY()
public:
	
	virtual void NativeOnInitialized() override;
	
	virtual FInv_SlotAvailabilityResult HasRoomForItem(UInv_ItemComponent* ItemComponent) const override;
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> Switcher;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventoryGrid> Grid_Equipment;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventoryGrid> Grid_Consumables;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventoryGrid> Grid_Crafting;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_Equipment;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_Consumables;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_Crafting;
	
	UFUNCTION()
	void ShowEquipment();
	
	UFUNCTION()
	void ShowConsumables();
	
	UFUNCTION()
	void ShowCrafting();
	
	void DisableButton(UButton* Button);

	void SetActiveGrid(UInv_InventoryGrid* InventoryGrid, UButton* Button);
};
