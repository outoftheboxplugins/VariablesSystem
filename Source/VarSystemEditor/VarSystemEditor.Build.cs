// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VarSystemEditor : ModuleRules
{
	public VarSystemEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
				"AssetTools",
				"MainFrame",
                "ClassViewer"
            } );

		PrivateIncludePaths.AddRange(
			new string[] {
				"VarSystemEditor/Private",
				"VarSystemEditor/Private/AssetTools",
				"VarSystemEditor/Private/Factories",
				"VarSystemEditor/Private/Shared",
				"VarSystemEditor/Private/Styles",
				"VarSystemEditor/Private/Toolkits",
				"VarSystemEditor/Private/Widgets",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[] {
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
				"VarSystem",
				"UnrealEd",
                "Projects"
			});

		PrivateIncludePathModuleNames.AddRange(
			new string[] {
                "ClassViewer",
                "AssetTools",
				"UnrealEd",
			});
	}
}
