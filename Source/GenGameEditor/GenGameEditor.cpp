#include "GenGameEditor.h"

#if WITH_GAMEPLAY_DEBUGGER
	#include "GameplayDebugger.h"
	#include "GameplayDebuggerCategory_GenGame.h"
#endif // WITH_GAMEPLAY_DEBUGGER

#include "Modules/ModuleManager.h"

IMPLEMENT_GAME_MODULE(FGenGameEditorModule, GenGameEditor);

void FGenGameEditorModule::StartupModule()
{
	IModuleInterface::StartupModule();

	UE_LOG(LogTemp, Log, TEXT("Loading GenGameEditor module"));

#if WITH_GAMEPLAY_DEBUGGER
	IGameplayDebugger& GameplayDebuggerModule = IGameplayDebugger::Get();
	GameplayDebuggerModule.RegisterCategory("GenGame", IGameplayDebugger::FOnGetCategory::CreateStatic(&FGameplayDebuggerCategory_GenGame::MakeInstance), EGameplayDebuggerCategoryState::EnabledInGameAndSimulate);
	GameplayDebuggerModule.NotifyCategoriesChanged();
#endif
}

void FGenGameEditorModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();

	UE_LOG(LogTemp, Log, TEXT("Shutting down GenGameEditor module"));
}
