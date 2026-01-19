// Copyright Callum Brogan.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Inv_PlayerController.generated.h"

class UInv_InventoryComponent;
class UInv_HUDWidget;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API AInv_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AInv_PlayerController();
	virtual void Tick( float DeltaTime ) override;
	
	UFUNCTION(BlueprintCallable, Category="InventorySystem")
	void ToggleInventory();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	
	void PrimaryInteract();	
	void CreateHUDWidget();
	void TraceForItem();
	
	TWeakObjectPtr<UInv_InventoryComponent> InventoryComponent;
	
	UPROPERTY(EditDefaultsOnly, Category="InventorySystem")
	TArray<TObjectPtr<UInputMappingContext>> DefaultIMCs;
	
	UPROPERTY(EditDefaultsOnly, Category="InventorySystem")
	TObjectPtr<UInputAction> ToggleInventoryAction;
	
	UPROPERTY(EditDefaultsOnly, Category="InventorySystem")
	TObjectPtr<UInputAction> PrimaryInteractAction;
	
	UPROPERTY(EditDefaultsOnly, Category="InventorySystem")
	TSubclassOf<UInv_HUDWidget> HUDWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UInv_HUDWidget> HUDWidget;
	
	UPROPERTY(EditDefaultsOnly, Category="InventorySystem")
	double TraceLength;
	
	UPROPERTY(EditDefaultsOnly, Category="InventorySystem")
	TEnumAsByte<ECollisionChannel> ItemTraceChannel;
	
	TWeakObjectPtr<AActor> ThisActor;
	TWeakObjectPtr<AActor> LastActor;
};
