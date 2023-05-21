// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerEquip.generated.h"

class UItemDefinition;
// This class does not need to be modified.
UINTERFACE()
class UPlayerEquip : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GENGAME_API IPlayerEquip
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	TSoftObjectPtr<UItemDefinition> GetEquippedItem();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void EquipItem(const TSoftObjectPtr<UItemDefinition>& Item);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void UseItem();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void FinishUseItem();
};
