// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SlimeTrail.generated.h"

UCLASS()
class GENGAME_API ASlimeTrail : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASlimeTrail();

	UFUNCTION(BlueprintImplementableEvent)
	void BurnAffectedActors();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<AActor*> AffectedActors;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float DamageInterval = 0.5f;
};
