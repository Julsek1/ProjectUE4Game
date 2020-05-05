// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project/TwinStickShooterPlayer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTwinStickShooterPlayer() {}
// Cross Module References
	PROJECT_API UClass* Z_Construct_UClass_ATwinStickShooterPlayer_NoRegister();
	PROJECT_API UClass* Z_Construct_UClass_ATwinStickShooterPlayer();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Project();
	PROJECT_API UFunction* Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward();
	PROJECT_API UFunction* Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	void ATwinStickShooterPlayer::StaticRegisterNativesATwinStickShooterPlayer()
	{
		UClass* Class = ATwinStickShooterPlayer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MoveForward", &ATwinStickShooterPlayer::execMoveForward },
			{ "MoveRight", &ATwinStickShooterPlayer::execMoveRight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward_Statics
	{
		struct TwinStickShooterPlayer_eventMoveForward_Parms
		{
			float Vertical;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Vertical;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward_Statics::NewProp_Vertical = { "Vertical", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TwinStickShooterPlayer_eventMoveForward_Parms, Vertical), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward_Statics::NewProp_Vertical,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TwinStickShooterPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATwinStickShooterPlayer, nullptr, "MoveForward", nullptr, nullptr, sizeof(TwinStickShooterPlayer_eventMoveForward_Parms), Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight_Statics
	{
		struct TwinStickShooterPlayer_eventMoveRight_Parms
		{
			float Horizontal;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Horizontal;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight_Statics::NewProp_Horizontal = { "Horizontal", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TwinStickShooterPlayer_eventMoveRight_Parms, Horizontal), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight_Statics::NewProp_Horizontal,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TwinStickShooterPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATwinStickShooterPlayer, nullptr, "MoveRight", nullptr, nullptr, sizeof(TwinStickShooterPlayer_eventMoveRight_Parms), Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATwinStickShooterPlayer_NoRegister()
	{
		return ATwinStickShooterPlayer::StaticClass();
	}
	struct Z_Construct_UClass_ATwinStickShooterPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Camera;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATwinStickShooterPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Project,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATwinStickShooterPlayer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATwinStickShooterPlayer_MoveForward, "MoveForward" }, // 2065143307
		{ &Z_Construct_UFunction_ATwinStickShooterPlayer_MoveRight, "MoveRight" }, // 4047352493
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATwinStickShooterPlayer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "TwinStickShooterPlayer.h" },
		{ "ModuleRelativePath", "TwinStickShooterPlayer.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATwinStickShooterPlayer_Statics::NewProp_SpringArm_MetaData[] = {
		{ "Category", "TwinStickShooterPlayer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TwinStickShooterPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATwinStickShooterPlayer_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATwinStickShooterPlayer, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATwinStickShooterPlayer_Statics::NewProp_SpringArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickShooterPlayer_Statics::NewProp_SpringArm_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATwinStickShooterPlayer_Statics::NewProp_Camera_MetaData[] = {
		{ "Category", "TwinStickShooterPlayer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TwinStickShooterPlayer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATwinStickShooterPlayer_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATwinStickShooterPlayer, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATwinStickShooterPlayer_Statics::NewProp_Camera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickShooterPlayer_Statics::NewProp_Camera_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATwinStickShooterPlayer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickShooterPlayer_Statics::NewProp_SpringArm,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATwinStickShooterPlayer_Statics::NewProp_Camera,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATwinStickShooterPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATwinStickShooterPlayer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATwinStickShooterPlayer_Statics::ClassParams = {
		&ATwinStickShooterPlayer::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATwinStickShooterPlayer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickShooterPlayer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATwinStickShooterPlayer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickShooterPlayer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATwinStickShooterPlayer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATwinStickShooterPlayer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATwinStickShooterPlayer, 4081325452);
	template<> PROJECT_API UClass* StaticClass<ATwinStickShooterPlayer>()
	{
		return ATwinStickShooterPlayer::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATwinStickShooterPlayer(Z_Construct_UClass_ATwinStickShooterPlayer, &ATwinStickShooterPlayer::StaticClass, TEXT("/Script/Project"), TEXT("ATwinStickShooterPlayer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATwinStickShooterPlayer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
