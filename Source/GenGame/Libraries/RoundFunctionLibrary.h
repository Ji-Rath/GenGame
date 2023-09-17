// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RoundFunctionLibrary.generated.h"

class AEnemy;
/**
 * 
 */
UCLASS()
class GENGAME_API URoundFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static TSoftClassPtr<AEnemy> DetermineNextEnemy(const TArray<TSoftClassPtr<AEnemy>>& EnemyPool, int Points);
};
