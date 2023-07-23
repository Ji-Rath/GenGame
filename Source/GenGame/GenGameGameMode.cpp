// Copyright Epic Games, Inc. All Rights Reserved.

#include "GenGameGameMode.h"
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

void AGenGameGameMode::TickWave()
{
	AActor* SpawnPoint = GetRandomSpawnPoint();

	const int GroupCount = FMath::RandRange(1,3);

	FTimerDelegate SpawnDelegate = FTimerDelegate::CreateUObject(this, &AGenGameGameMode::SpawnEnemy, SpawnPoint);
	for(int i=0;i<GroupCount;i++)
	{
		if (EnemiesToSpawn > 0)
		{
			FTimerHandle Handle;
			GetWorldTimerManager().SetTimer(Handle, SpawnDelegate, EnemyGroupSpawnRate*i, false);
		}
		else
		{
			break;
		}
	}
}
