#pragma once

#if WITH_GAMEPLAY_DEBUGGER

#include "GameplayDebuggerCategory.h"

class FGameplayDebuggerCategory_GenGame : public FGameplayDebuggerCategory
{
public:
	FGameplayDebuggerCategory_GenGame();

	virtual void CollectData(APlayerController* OwnerPC, AActor* DebugActor) override;
	virtual void DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext) override;

	static TSharedRef<FGameplayDebuggerCategory> MakeInstance();

protected:
	struct FRepData
	{
		// Put all data you want to display here
		int Round;
		int EnemyPoints;
		int TimeTillNextWave;
        
		void Serialize(FArchive& Ar);
	};
    
	FRepData DataPack;
};
#endif