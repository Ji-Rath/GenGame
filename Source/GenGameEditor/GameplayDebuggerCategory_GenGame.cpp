#include "GameplayDebuggerCategory_GenGame.h"

#if WITH_GAMEPLAY_DEBUGGER

FGameplayDebuggerCategory_GenGame::FGameplayDebuggerCategory_GenGame()
{
	SetDataPackReplication(&DataPack);
}

void FGameplayDebuggerCategory_GenGame::CollectData(APlayerController* OwnerPC, AActor* DebugActor)
{
	if (OwnerPC)
	{
		DataPack.ActorName = OwnerPC->GetPawn()->GetName();
	}
}

void FGameplayDebuggerCategory_GenGame::DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext)
{
	if (!DataPack.ActorName.IsEmpty())
	{
		CanvasContext.Printf(TEXT("{yellow}Actor name: {white}%s"), *DataPack.ActorName);
	}
}

TSharedRef<FGameplayDebuggerCategory> FGameplayDebuggerCategory_GenGame::MakeInstance()
{
	return MakeShareable(new FGameplayDebuggerCategory_GenGame());
}

void FGameplayDebuggerCategory_GenGame::FRepData::Serialize(FArchive& Ar)
{
	Ar << ActorName;
}

#endif // WITH_GAMEPLAY_DEBUGGER