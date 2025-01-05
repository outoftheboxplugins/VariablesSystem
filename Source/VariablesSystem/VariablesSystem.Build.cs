// Copyright Out-of-the-Box Plugins 2018-2025. All Rights Reserved.
namespace UnrealBuildTool.Rules
{
	public class VariablesSystem : ModuleRules
	{
		public VariablesSystem(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

			PublicDependencyModuleNames.AddRange(
				new string[] {
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "GameplayTags"
                });
		}
	}
}
