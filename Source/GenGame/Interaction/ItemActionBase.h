// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemActionBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class GENGAME_API UItemActionBase : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	AActor* ActionPerformer;
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PerformAction(AActor* OwnerActor);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EndAction();
	
	UWorld* GetWorld() const;
};
