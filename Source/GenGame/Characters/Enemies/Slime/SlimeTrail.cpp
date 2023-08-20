// Fill out your copyright notice in the Description page of Project Settings.


#include "SlimeTrail.h"


// Sets default values
ASlimeTrail::ASlimeTrail()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ASlimeTrail::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		FTimerHandle Handle;
		FTimerDelegate TimerDelegate;
		GetWorldTimerManager().SetTimer(Handle, FTimerDelegate::CreateUObject(this, &ASlimeTrail::BurnAffectedActors), DamageInterval, true);
	}
}

