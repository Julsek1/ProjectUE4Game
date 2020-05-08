// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project/Public/PRJPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePRJPawn() {}
// Cross Module References
	PROJECT_API UClass* Z_Construct_UClass_APRJPawn_NoRegister();
	PROJECT_API UClass* Z_Construct_UClass_APRJPawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_Project();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void APRJPawn::StaticRegisterNativesAPRJPawn()
	{
	}
	UClass* Z_Construct_UClass_APRJPawn_NoRegister()
	{
		return APRJPawn::StaticClass();
	}
	struct Z_Construct_UClass_APRJPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sideforce_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Sideforce;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Forwardforce_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Forwardforce;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Camera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Cube_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Cube;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APRJPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_Project,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APRJPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "PRJPawn.h" },
		{ "ModuleRelativePath", "Public/PRJPawn.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APRJPawn_Statics::NewProp_Sideforce_MetaData[] = {
		{ "Category", "Floats" },
		{ "ModuleRelativePath", "Public/PRJPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APRJPawn_Statics::NewProp_Sideforce = { "Sideforce", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APRJPawn, Sideforce), METADATA_PARAMS(Z_Construct_UClass_APRJPawn_Statics::NewProp_Sideforce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APRJPawn_Statics::NewProp_Sideforce_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APRJPawn_Statics::NewProp_Forwardforce_MetaData[] = {
		{ "Category", "Floats" },
		{ "ModuleRelativePath", "Public/PRJPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APRJPawn_Statics::NewProp_Forwardforce = { "Forwardforce", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APRJPawn, Forwardforce), METADATA_PARAMS(Z_Construct_UClass_APRJPawn_Statics::NewProp_Forwardforce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APRJPawn_Statics::NewProp_Forwardforce_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APRJPawn_Statics::NewProp_Camera_MetaData[] = {
		{ "Category", "Setup" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PRJPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APRJPawn_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APRJPawn, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APRJPawn_Statics::NewProp_Camera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APRJPawn_Statics::NewProp_Camera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APRJPawn_Statics::NewProp_SpringArm_MetaData[] = {
		{ "Category", "Setup" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PRJPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APRJPawn_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APRJPawn, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APRJPawn_Statics::NewProp_SpringArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APRJPawn_Statics::NewProp_SpringArm_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APRJPawn_Statics::NewProp_Cube_MetaData[] = {
		{ "Category", "Setup" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PRJPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APRJPawn_Statics::NewProp_Cube = { "Cube", nullptr, (EPropertyFlags)0x00200800000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APRJPawn, Cube), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APRJPawn_Statics::NewProp_Cube_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APRJPawn_Statics::NewProp_Cube_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APRJPawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APRJPawn_Statics::NewProp_Sideforce,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APRJPawn_Statics::NewProp_Forwardforce,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APRJPawn_Statics::NewProp_Camera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APRJPawn_Statics::NewProp_SpringArm,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APRJPawn_Statics::NewProp_Cube,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APRJPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APRJPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APRJPawn_Statics::ClassParams = {
		&APRJPawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APRJPawn_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APRJPawn_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APRJPawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APRJPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APRJPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APRJPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APRJPawn, 3457254065);
	template<> PROJECT_API UClass* StaticClass<APRJPawn>()
	{
		return APRJPawn::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APRJPawn(Z_Construct_UClass_APRJPawn, &APRJPawn::StaticClass, TEXT("/Script/Project"), TEXT("APRJPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APRJPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
