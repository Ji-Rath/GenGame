// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UENUM(BlueprintType)
enum class EInteractType : uint8
{
	SingleUse,
	Continuous
};

// This class does not need to be modified.
UINTERFACE()
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GENGAME_API IInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Perform an interaction on the interactable
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintAuthorityOnly)
	EInteractType ServerPerformInteraction(const AActor* Interactor);

	// Declares an interaction as finished, used primarily for continuous interaction
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void ServerFinishInteraction(const AActor* Interactor);

	// Returns whether the actor can be interacted with
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool CanInteract(const AActor* Interactor) const;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	EInteractType GetInteractType() const;
};
