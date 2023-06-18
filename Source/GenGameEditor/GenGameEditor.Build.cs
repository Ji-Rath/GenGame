// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GenGameEditor : ModuleRules
{
	public GenGameEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "GenGame", "GameplayDebugger" });
		
		SetupGameplayDebuggerSupport(base.Target);
	}
}
