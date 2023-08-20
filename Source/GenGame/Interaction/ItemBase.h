// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class GENGAME_API UItemBase : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	AActor* ActionPerformer;
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PerformAction(AActor* OwnerActor);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void ReloadAction(AActor* OwnerActor);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EndAction();

	// Allows the Object to get a valid UWorld from it's outer.
	virtual UWorld* GetWorld() const override;

	UFUNCTION(BlueprintPure, Category = "My Object")
	AActor* GetOwningActor() const;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual bool IsSupportedForNetworking() const override
	{
		return true;
	}
	
	virtual int32 GetFunctionCallspace(UFunction* Function, FFrame* Stack) override;

	// Call "Remote" (aka, RPC) functions through the actors NetDriver
	virtual bool CallRemoteFunction(UFunction* Function, void* Parms, struct FOutParmRec* OutParms, FFrame* Stack) override;

	/*
	* Optional
	* Since this is a replicated object, typically only the Server should create and destroy these
	* Provide a custom destroy function to ensure these conditions are met.
	*/
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "My Object")
	void Destroy();
};
