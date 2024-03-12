// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAsteroids_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Asteroids;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Asteroids()
	{
		if (!Z_Registration_Info_UPackage__Script_Asteroids.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Asteroids",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xD09FEDDD,
				0x617D106E,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Asteroids.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Asteroids.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Asteroids(Z_Construct_UPackage__Script_Asteroids, TEXT("/Script/Asteroids"), Z_Registration_Info_UPackage__Script_Asteroids, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xD09FEDDD, 0x617D106E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
