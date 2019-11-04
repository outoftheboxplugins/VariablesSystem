// Copyright Out-of-the-Box Plugins 2018-2019. All Rights Reserved.

//TODO: Investigate if we should use a PCH and how.

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
                });
		}
	}
}
