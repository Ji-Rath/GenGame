// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenGame/Weapons/Suckable.h"
#include "Enemy.generated.h"

enum class EEnemyState : uint8;

UCLASS()
class GENGAME_API AEnemy : public ACharacter, public ISuckable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, ReplicatedUsing="OnRepEnemyState")
	EEnemyState EnemyState;

	// Points required in order to have the possibility of this enemy spawning
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PointThreshold = 0;

	// Points required to actually spawn this enemy
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PointCost = 1;

	UFUNCTION(BlueprintImplementableEvent)
	void OnRepEnemyState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEnemyState DefaultState;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetStateFor(EEnemyState NewState, float Duration);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintAuthorityOnly)
	void SetState(EEnemyState NewState);
};
