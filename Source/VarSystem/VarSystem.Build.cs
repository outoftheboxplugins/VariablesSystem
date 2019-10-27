// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class VarSystem : ModuleRules
	{
		public VarSystem(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

			PublicDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
                    "Engine",
                    "AssetTools",
                "ContentBrowser",
                "Core",
                "CoreUObject",
                "DesktopWidgets",
                "EditorStyle",
                "Engine",
                "InputCore",
                "Projects",
                "Slate",
                "SlateCore",
                "UnrealEd",
                "Projects",
                "MainFrame",
                });

			PrivateIncludePaths.AddRange(
				new string[] {
				});
		}
	}
}
