// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HW : ModuleRules
{
	public HW(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"HW",
			"HW/Variant_Platforming",
			"HW/Variant_Platforming/Animation",
			"HW/Variant_Combat",
			"HW/Variant_Combat/AI",
			"HW/Variant_Combat/Animation",
			"HW/Variant_Combat/Gameplay",
			"HW/Variant_Combat/Interfaces",
			"HW/Variant_Combat/UI",
			"HW/Variant_SideScrolling",
			"HW/Variant_SideScrolling/AI",
			"HW/Variant_SideScrolling/Gameplay",
			"HW/Variant_SideScrolling/Interfaces",
			"HW/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
