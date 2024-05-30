// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Asteroids : ModuleRules
{
	public Asteroids(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { 

            "Core", 
            "CoreUObject", 
            "Engine", 
            "InputCore", 
            "OnlineSubsystem", 
            "OnlineSubsystemUtils", 
            "Slate",
            "SlateCore",
            "Blutility"

        });

        PrivateDependencyModuleNames.AddRange(new string[] {

        });

        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
