// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project/Public/PRJEndPoint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePRJEndPoint() {}
// Cross Module References
	PROJECT_API UClass* Z_Construct_UClass_APRJEndPoint_NoRegister();
	PROJECT_API UClass* Z_Construct_UClass_APRJEndPoint();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Project();
// End Cross Module References
	void APRJEndPoint::StaticRegisterNativesAPRJEndPoint()
	{
	}
	UClass* Z_Construct_UClass_APRJEndPoint_NoRegister()
	{
		return APRJEndPoint::StaticClass();
	}
	struct Z_Construct_UClass_APRJEndPoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APRJEndPoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Project,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APRJEndPoint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PRJEndPoint.h" },
		{ "ModuleRelativePath", "Public/PRJEndPoint.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APRJEndPoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APRJEndPoint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APRJEndPoint_Statics::ClassParams = {
		&APRJEndPoint::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APRJEndPoint_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APRJEndPoint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APRJEndPoint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APRJEndPoint_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APRJEndPoint, 2438090762);
	template<> PROJECT_API UClass* StaticClass<APRJEndPoint>()
	{
		return APRJEndPoint::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APRJEndPoint(Z_Construct_UClass_APRJEndPoint, &APRJEndPoint::StaticClass, TEXT("/Script/Project"), TEXT("APRJEndPoint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APRJEndPoint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
