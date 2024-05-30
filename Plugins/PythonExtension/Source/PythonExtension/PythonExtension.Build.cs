using static UnrealBuildTool.ModuleRules;
using UnrealBuildTool;

public class PythonExtension : ModuleRules
{
    public PythonExtension(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { "PythonScriptPlugin" });
    }
}
