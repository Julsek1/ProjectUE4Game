// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT_ParentPlayer_generated_h
#error "ParentPlayer.generated.h already included, missing '#pragma once' in ParentPlayer.h"
#endif
#define PROJECT_ParentPlayer_generated_h

#define Project_Source_Project_ParentPlayer_h_12_SPARSE_DATA
#define Project_Source_Project_ParentPlayer_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execHeal) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_HealingAmount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Heal(Z_Param_HealingAmount); \
		P_NATIVE_END; \
	}


#define Project_Source_Project_ParentPlayer_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHeal) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_HealingAmount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Heal(Z_Param_HealingAmount); \
		P_NATIVE_END; \
	}


#define Project_Source_Project_ParentPlayer_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAParentPlayer(); \
	friend struct Z_Construct_UClass_AParentPlayer_Statics; \
public: \
	DECLARE_CLASS(AParentPlayer, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project"), NO_API) \
	DECLARE_SERIALIZER(AParentPlayer)


#define Project_Source_Project_ParentPlayer_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAParentPlayer(); \
	friend struct Z_Construct_UClass_AParentPlayer_Statics; \
public: \
	DECLARE_CLASS(AParentPlayer, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project"), NO_API) \
	DECLARE_SERIALIZER(AParentPlayer)


#define Project_Source_Project_ParentPlayer_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AParentPlayer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AParentPlayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AParentPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AParentPlayer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AParentPlayer(AParentPlayer&&); \
	NO_API AParentPlayer(const AParentPlayer&); \
public:


#define Project_Source_Project_ParentPlayer_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AParentPlayer(AParentPlayer&&); \
	NO_API AParentPlayer(const AParentPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AParentPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AParentPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AParentPlayer)


#define Project_Source_Project_ParentPlayer_h_12_PRIVATE_PROPERTY_OFFSET
#define Project_Source_Project_ParentPlayer_h_9_PROLOG
#define Project_Source_Project_ParentPlayer_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_Source_Project_ParentPlayer_h_12_PRIVATE_PROPERTY_OFFSET \
	Project_Source_Project_ParentPlayer_h_12_SPARSE_DATA \
	Project_Source_Project_ParentPlayer_h_12_RPC_WRAPPERS \
	Project_Source_Project_ParentPlayer_h_12_INCLASS \
	Project_Source_Project_ParentPlayer_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project_Source_Project_ParentPlayer_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_Source_Project_ParentPlayer_h_12_PRIVATE_PROPERTY_OFFSET \
	Project_Source_Project_ParentPlayer_h_12_SPARSE_DATA \
	Project_Source_Project_ParentPlayer_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Project_Source_Project_ParentPlayer_h_12_INCLASS_NO_PURE_DECLS \
	Project_Source_Project_ParentPlayer_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_API UClass* StaticClass<class AParentPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project_Source_Project_ParentPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
