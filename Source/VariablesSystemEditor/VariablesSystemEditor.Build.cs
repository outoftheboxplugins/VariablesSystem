// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

using UnrealBuildTool;

public class VariablesSystemEditor : ModuleRules
{
	public VariablesSystemEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateDependencyModuleNames.AddRange(
			new string[] {
                "BlueprintGraph",
                "ContentBrowser",
                "CoreUObject",
                "KismetCompiler",
				"Core",
				"EditorStyle",
				"Engine",
				"InputCore",
				"Slate",
				"SlateCore",
				"UnrealEd",
				"VariablesSystem",
            });
	}
}
