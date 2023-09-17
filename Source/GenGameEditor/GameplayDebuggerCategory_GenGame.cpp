#include "GameplayDebuggerCategory_GenGame.h"

#include "GenGame/GenGameGameMode.h"
#include "GenGame/GenGameState.h"
#include "Kismet/GameplayStatics.h"

#if WITH_GAMEPLAY_DEBUGGER

FGameplayDebuggerCategory_GenGame::FGameplayDebuggerCategory_GenGame()
{
	SetDataPackReplication(&DataPack);
}

void FGameplayDebuggerCategory_GenGame::CollectData(APlayerController* OwnerPC, AActor* DebugActor)
{
	if (AGameModeBase* Gamemode = UGameplayStatics::GetGameMode(OwnerPC))
	{
		if (AGenGameGameMode* GenGameMode = Cast<AGenGameGameMode>(Gamemode))
		{
			AGenGameState* GameState = GenGameMode->GetGameState<AGenGameState>();
			check(GameState);
			
			DataPack.EnemyPoints = GenGameMode->RoundPoints;
			DataPack.Round = GameState->Round;
			//DataPack.TimeTillNextWave = GenGameMode;
		}
	}
}

void FGameplayDebuggerCategory_GenGame::DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext)
{
	CanvasContext.Printf(TEXT("{yellow}Enemy points: {white}%d"), DataPack.EnemyPoints);
	CanvasContext.Printf(TEXT("{yellow}Round: {white}%d"), DataPack.Round);
	CanvasContext.Printf(TEXT("{yellow}Time until next wave: {white}%d"), DataPack.TimeTillNextWave);
}

TSharedRef<FGameplayDebuggerCategory> FGameplayDebuggerCategory_GenGame::MakeInstance()
{
	return MakeShareable(new FGameplayDebuggerCategory_GenGame());
}

void FGameplayDebuggerCategory_GenGame::FRepData::Serialize(FArchive& Ar)
{
	Ar << EnemyPoints;
	Ar << Round;
	Ar << TimeTillNextWave;
}

#endif // WITH_GAMEPLAY_DEBUGGER