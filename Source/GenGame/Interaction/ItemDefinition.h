// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDefinition.generated.h"

class UItemActionBase;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class GENGAME_API UItemDefinition : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UStaticMesh> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<UItemActionBase> Action;
};
