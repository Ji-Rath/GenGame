// Fill out your copyright notice in the Description page of Project Settings.


#include "GenGameState.h"

#include "Net/UnrealNetwork.h"

void AGenGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGenGameState, Round);
}
