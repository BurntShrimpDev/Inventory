// Copyright Callum Brogan.


#include "Player/Inv_PlayerController.h"
#include "InventorySystem.h"

void AInv_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogInventory, Log, TEXT("BeginPlay for PlayerController"));
}
