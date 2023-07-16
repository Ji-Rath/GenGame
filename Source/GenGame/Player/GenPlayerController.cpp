// Fill out your copyright notice in the Description page of Project Settings.


#include "GenPlayerController.h"


// Sets default values
AGenPlayerController::AGenPlayerController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGenPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGenPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGenPlayerController::BeginSpectating()
{
	BeginSpectatingState();
}

