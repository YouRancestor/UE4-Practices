// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class TestBlankPlugin : ModuleRules
	{
		public TestBlankPlugin(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					"Private",
					// ... add other private include paths required here ...
                    "Runtime/CoreUObject/Public/",
                    "Core",
                    "CoreUObject",
                    "AssetTools",
                    "SlateCore",
                    "UnrealEd",

                }
                );

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					// ... add other public dependencies that you statically link with here ...
                }
                );

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
                    "Core",
                    "CoreUObject",
                    "AssetTools",
                    "SlateCore",
                    "UnrealEd",

                }
                );

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
                }
				);
		}
	}
}