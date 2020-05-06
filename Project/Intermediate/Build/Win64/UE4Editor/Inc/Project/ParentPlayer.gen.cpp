// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project/ParentPlayer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeParentPlayer() {}
// Cross Module References
	PROJECT_API UClass* Z_Construct_UClass_AParentPlayer_NoRegister();
	PROJECT_API UClass* Z_Construct_UClass_AParentPlayer();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Project();
	PROJECT_API UFunction* Z_Construct_UFunction_AParentPlayer_Heal();
// End Cross Module References
	void AParentPlayer::StaticRegisterNativesAParentPlayer()
	{
		UClass* Class = AParentPlayer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Heal", &AParentPlayer::execHeal },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AParentPlayer_Heal_Statics
	{
		struct ParentPlayer_eventHeal_Parms
		{
			float HealingAmount;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HealingAmount;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AParentPlayer_Heal_Statics::NewProp_HealingAmount = { "HealingAmount", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ParentPlayer_eventHeal_Parms, HealingAmount), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AParentPlayer_Heal_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AParentPlayer_Heal_Statics::NewProp_HealingAmount,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AParentPlayer_Heal_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ParentPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AParentPlayer_Heal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AParentPlayer, nullptr, "Heal", nullptr, nullptr, sizeof(ParentPlayer_eventHeal_Parms), Z_Construct_UFunction_AParentPlayer_Heal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AParentPlayer_Heal_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AParentPlayer_Heal_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AParentPlayer_Heal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AParentPlayer_Heal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AParentPlayer_Heal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AParentPlayer_NoRegister()
	{
		return AParentPlayer::StaticClass();
	}
	struct Z_Construct_UClass_AParentPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AParentPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Project,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AParentPlayer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AParentPlayer_Heal, "Heal" }, // 2421445352
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AParentPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ParentPlayer.h" },
		{ "ModuleRelativePath", "ParentPlayer.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AParentPlayer_Statics::NewProp_Health_MetaData[] = {
		{ "Category", "ParentPlayer" },
		{ "ModuleRelativePath", "ParentPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AParentPlayer_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AParentPlayer, Health), METADATA_PARAMS(Z_Construct_UClass_AParentPlayer_Statics::NewProp_Health_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AParentPlayer_Statics::NewProp_Health_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AParentPlayer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AParentPlayer_Statics::NewProp_Health,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AParentPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AParentPlayer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AParentPlayer_Statics::ClassParams = {
		&AParentPlayer::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AParentPlayer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AParentPlayer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AParentPlayer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AParentPlayer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AParentPlayer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AParentPlayer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AParentPlayer, 2035938110);
	template<> PROJECT_API UClass* StaticClass<AParentPlayer>()
	{
		return AParentPlayer::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AParentPlayer(Z_Construct_UClass_AParentPlayer, &AParentPlayer::StaticClass, TEXT("/Script/Project"), TEXT("AParentPlayer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AParentPlayer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
