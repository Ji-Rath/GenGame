// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vacuum.generated.h"

class UBoxComponent;

UCLASS()
class GENGAME_API AVacuum : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVacuum();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* CollisionZone;

	UFUNCTION()
	void EnterVacuumZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void LeaveVacuumZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Rate at which to destroy enemies
	UPROPERTY(EditAnywhere)
	float VacuumRate = 1.f;

	TMap<TWeakObjectPtr<AActor>, FTimerHandle> TimerHandles;
};
