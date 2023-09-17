// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GenGameGameMode.generated.h"

UCLASS(minimalapi)
class AGenGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RoundPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EnemyGroupSpawnRate = 0.5f;

	AGenGameGameMode();

	virtual void Reset() override;

	UFUNCTION(BlueprintCallable)
	virtual void TickWave();

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnEnemy(AActor* SpawnPoint);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	AActor* GetRandomSpawnPoint();
};



