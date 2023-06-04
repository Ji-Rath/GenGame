// Copyright Epic Games, Inc. All Rights Reserved.

#include "GenGameGameMode.h"
#include "GenGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGenGameGameMode::AGenGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AGenGameGameMode::Reset()
{
	Super::Reset();
	//@todo implement reset for gamemode functionality
}
