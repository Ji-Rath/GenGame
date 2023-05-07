// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenGameBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GENGAME_API UGenGameBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static void FilterArrayByInterface(const TArray<AActor*>& Actors, const TSubclassOf<UInterface> Interface, TArray<AActor*>& OutActors);
};
