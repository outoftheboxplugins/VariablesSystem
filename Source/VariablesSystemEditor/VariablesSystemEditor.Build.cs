// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VariablesSystemEditor : ModuleRules
{
	public VariablesSystemEditor(ReadOnlyTargetRules Target) : base(Target)
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
				"VariablesSystemEditor/Private",
				"VariablesSystemEditor/Private/AssetTools",
				"VariablesSystemEditor/Private/Factories",
				"VariablesSystemEditor/Private/Shared",
				"VariablesSystemEditor/Private/Styles",
				"VariablesSystemEditor/Private/Toolkits",
				"VariablesSystemEditor/Private/Widgets",
				"VariablesSystemEditor/Private/Nodes",
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
				"VariablesSystem",
                "Projects",
                "BlueprintGraph",
                "GraphEditor",
                "KismetCompiler",
            } );

        if (Target.Type == TargetRules.TargetType.Editor)
        {
            PrivateDependencyModuleNames.AddRange(
            new string[]
            {
            "UnrealEd"
            }
            );
        }

        PrivateIncludePathModuleNames.AddRange(
			new string[] {
                "ClassViewer",
                "AssetTools",
			});
	}
}
