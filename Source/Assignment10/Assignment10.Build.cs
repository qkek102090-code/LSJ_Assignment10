// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Assignment10 : ModuleRules
{
	public Assignment10(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
