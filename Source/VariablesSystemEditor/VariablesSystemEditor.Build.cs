// Copyright Out-of-the-Box Plugins 2018-2021. All Rights Reserved.
using UnrealBuildTool;

public class VariablesSystemEditor : ModuleRules
{
	public VariablesSystemEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.AddRange(
			new string[] {
				"VariablesSystem/Generated/Library",
				"VariablesSystemEditor/Private",
				"VariablesSystemEditor/Private/AssetTools",
				"VariablesSystemEditor/Private/Factories",
				"VariablesSystemEditor/Private/Nodes",
				"VariablesSystemEditor/Private/WatchWidget"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[] {
                "BlueprintGraph",
				"GraphEditor",
                "ContentBrowser",
                "CoreUObject",
                "KismetCompiler",
				"Core",
				"WorkspaceMenuStructure",
				"EditorStyle",
				"Engine",
				"InputCore",
				"Slate",
				"SlateCore",
				"UnrealEd",
				"VariablesSystem",
                "GameplayTags"
            });
	}
}
