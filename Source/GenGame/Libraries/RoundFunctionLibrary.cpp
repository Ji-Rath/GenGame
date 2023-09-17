// Fill out your copyright notice in the Description page of Project Settings.


#include "RoundFunctionLibrary.h"

#include "GenGame/Characters/Enemies/Enemy.h"

TSoftClassPtr<AEnemy> URoundFunctionLibrary::DetermineNextEnemy(const TArray<TSoftClassPtr<AEnemy>>& EnemyPool,
                                                                int Points)
{
	TSoftClassPtr<AEnemy> OutClass;
	TArray<TSoftClassPtr<AEnemy>> FilteredClasses = EnemyPool.FilterByPredicate([Points](const TSoftClassPtr<AEnemy>& EnemyClass)
	{
		if (EnemyClass.Get())
		{
			const AEnemy* DefaultEnemy = EnemyClass.Get()->GetDefaultObject<AEnemy>();
			const bool bWithinThreshold = DefaultEnemy->PointThreshold <= Points;
			const bool bWithinCost = DefaultEnemy->PointCost <= Points;
			return bWithinThreshold && bWithinCost;
		}
		return false;
	});

	if (FilteredClasses.IsEmpty()) { return OutClass; }
	
	const int RandomIndex = FMath::RandRange(0, FilteredClasses.Num()-1);
	OutClass = FilteredClasses[RandomIndex];
	return OutClass;
}
