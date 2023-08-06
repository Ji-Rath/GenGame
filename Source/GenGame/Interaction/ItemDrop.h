// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemDrop.generated.h"

class UItemBase;

UCLASS()
class GENGAME_API AItemDrop : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemDrop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, meta=(ExposeOnSpawn))
	UItemBase* ItemObject;
};
