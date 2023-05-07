// Fill out your copyright notice in the Description page of Project Settings.


#include "GenGameBlueprintLibrary.h"

void UGenGameBlueprintLibrary::FilterArrayByInterface(const TArray<AActor*>& Actors, const TSubclassOf<UInterface> Interface, TArray<AActor*>& OutActors)
{
	for(AActor* Actor : Actors)
	{
		if (Actor->GetClass()->ImplementsInterface(Interface))
		{
			OutActors.Emplace(Actor);
		}
	}
}
