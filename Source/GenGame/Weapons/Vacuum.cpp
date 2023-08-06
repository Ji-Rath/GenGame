// Fill out your copyright notice in the Description page of Project Settings.


#include "Vacuum.h"

#include "Suckable.h"
#include "Components/BoxComponent.h"
#include "Components/ShapeComponent.h"
#include "GenGame/Characters/Enemy.h"


// Sets default values
AVacuum::AVacuum()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionZone = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionArea"));
}

// Called when the game starts or when spawned
void AVacuum::BeginPlay()
{
	Super::BeginPlay();

	CollisionZone->OnComponentBeginOverlap.AddDynamic(this, &AVacuum::EnterVacuumZone);
	CollisionZone->OnComponentEndOverlap.AddDynamic(this, &AVacuum::LeaveVacuumZone);

	//@todo get initially overlapping components
}

// Called every frame
void AVacuum::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVacuum::EnterVacuumZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//@todo change to interface check?
	if (OtherActor->Implements<USuckable>())
	{
		ISuckable::Execute_BeginSuck(OtherActor);
		
		FTimerHandle TimerHandle;
		FTimerDelegate TimerDelegate;

		TWeakObjectPtr<AActor> WeakActor = OtherActor;
		TWeakObjectPtr<AVacuum> WeakThis = this;
		TimerDelegate.BindLambda([WeakActor, WeakThis]()
		{
			if (AActor* StrongActor = WeakActor.Get())
			{
				if (AVacuum* StrongThis = WeakThis.Get())
				{
					StrongThis->OnSuckObject.Broadcast(StrongActor);
					StrongThis->TimerHandles.Remove(WeakActor);
				}
			}
		});
		GetWorldTimerManager().SetTimer(TimerHandle, TimerDelegate, VacuumRate, false);
		TimerHandles.Add(WeakActor, TimerHandle);
	}
}

void AVacuum::LeaveVacuumZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (FTimerHandle* TimerHandle = TimerHandles.Find(OtherActor))
	{
		ISuckable::Execute_FinishSuck(OtherActor);
		GetWorldTimerManager().ClearTimer(*TimerHandle);
	}
}

