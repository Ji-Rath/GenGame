﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Suckable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class USuckable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GENGAME_API ISuckable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent)
	void BeginSuck();

	UFUNCTION(BlueprintImplementableEvent)
	void FinishSuck();
};
