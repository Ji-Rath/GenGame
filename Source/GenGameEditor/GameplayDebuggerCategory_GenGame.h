#pragma once

#if WITH_GAMEPLAY_DEBUGGER

#include "GameplayDebuggerCategory.h"

class FGameplayDebuggerCategory_GenGame : public FGameplayDebuggerCategory
{
public:
	FGameplayDebuggerCategory_GenGame();

	void CollectData(APlayerController* OwnerPC, AActor* DebugActor) override;
	void DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext) override;

	static TSharedRef<FGameplayDebuggerCategory> MakeInstance();

protected:
	struct FRepData
	{
		// Put all data you want to display here
		FString ActorName;
        
		void Serialize(FArchive& Ar);
	};
    
	FRepData DataPack;
};
#endif