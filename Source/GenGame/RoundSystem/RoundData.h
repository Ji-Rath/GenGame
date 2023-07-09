// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "RoundData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct GENGAME_API FRoundData : public FTableRowBase
{
	GENERATED_BODY()
public:

	// The base amount of enemies to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BaseEnemies = 0;

	// The spawnrate curve of enemies
	// x - round #
	// y - # enemies
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UCurveFloat> SpawnRateCurve;

	// Max time to give players to complete round
	// Will forcefully start the next round if the time is passed
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseNextWaveTime = 300;

	// The amount of waves this level will have
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Waves = 1;

	// The level to load
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UWorld> LevelToLoad;
};
