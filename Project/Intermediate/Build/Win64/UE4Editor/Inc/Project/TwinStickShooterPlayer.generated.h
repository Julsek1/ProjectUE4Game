// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AObjective;
#ifdef PROJECT_TwinStickShooterPlayer_generated_h
#error "TwinStickShooterPlayer.generated.h already included, missing '#pragma once' in TwinStickShooterPlayer.h"
#endif
#define PROJECT_TwinStickShooterPlayer_generated_h

#define Project_Source_Project_TwinStickShooterPlayer_h_21_SPARSE_DATA
#define Project_Source_Project_TwinStickShooterPlayer_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execReceiveObjective) \
	{ \
		P_GET_OBJECT(AObjective,Z_Param_Objective); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ReceiveObjective(Z_Param_Objective); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRotateY) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_RotationY); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RotateY(Z_Param_RotationY); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRotateX) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_RotationX); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RotateX(Z_Param_RotationX); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveRight) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Horizontal); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveRight(Z_Param_Horizontal); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveForward) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Vertical); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveForward(Z_Param_Vertical); \
		P_NATIVE_END; \
	}


#define Project_Source_Project_TwinStickShooterPlayer_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReceiveObjective) \
	{ \
		P_GET_OBJECT(AObjective,Z_Param_Objective); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ReceiveObjective(Z_Param_Objective); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRotateY) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_RotationY); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RotateY(Z_Param_RotationY); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRotateX) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_RotationX); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RotateX(Z_Param_RotationX); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveRight) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Horizontal); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveRight(Z_Param_Horizontal); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveForward) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Vertical); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveForward(Z_Param_Vertical); \
		P_NATIVE_END; \
	}


#define Project_Source_Project_TwinStickShooterPlayer_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATwinStickShooterPlayer(); \
	friend struct Z_Construct_UClass_ATwinStickShooterPlayer_Statics; \
public: \
	DECLARE_CLASS(ATwinStickShooterPlayer, AParentPlayer, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project"), NO_API) \
	DECLARE_SERIALIZER(ATwinStickShooterPlayer)


#define Project_Source_Project_TwinStickShooterPlayer_h_21_INCLASS \
private: \
	static void StaticRegisterNativesATwinStickShooterPlayer(); \
	friend struct Z_Construct_UClass_ATwinStickShooterPlayer_Statics; \
public: \
	DECLARE_CLASS(ATwinStickShooterPlayer, AParentPlayer, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project"), NO_API) \
	DECLARE_SERIALIZER(ATwinStickShooterPlayer)


#define Project_Source_Project_TwinStickShooterPlayer_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATwinStickShooterPlayer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATwinStickShooterPlayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATwinStickShooterPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATwinStickShooterPlayer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATwinStickShooterPlayer(ATwinStickShooterPlayer&&); \
	NO_API ATwinStickShooterPlayer(const ATwinStickShooterPlayer&); \
public:


#define Project_Source_Project_TwinStickShooterPlayer_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATwinStickShooterPlayer(ATwinStickShooterPlayer&&); \
	NO_API ATwinStickShooterPlayer(const ATwinStickShooterPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATwinStickShooterPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATwinStickShooterPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATwinStickShooterPlayer)


#define Project_Source_Project_TwinStickShooterPlayer_h_21_PRIVATE_PROPERTY_OFFSET
#define Project_Source_Project_TwinStickShooterPlayer_h_18_PROLOG
#define Project_Source_Project_TwinStickShooterPlayer_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_Source_Project_TwinStickShooterPlayer_h_21_PRIVATE_PROPERTY_OFFSET \
	Project_Source_Project_TwinStickShooterPlayer_h_21_SPARSE_DATA \
	Project_Source_Project_TwinStickShooterPlayer_h_21_RPC_WRAPPERS \
	Project_Source_Project_TwinStickShooterPlayer_h_21_INCLASS \
	Project_Source_Project_TwinStickShooterPlayer_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project_Source_Project_TwinStickShooterPlayer_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_Source_Project_TwinStickShooterPlayer_h_21_PRIVATE_PROPERTY_OFFSET \
	Project_Source_Project_TwinStickShooterPlayer_h_21_SPARSE_DATA \
	Project_Source_Project_TwinStickShooterPlayer_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	Project_Source_Project_TwinStickShooterPlayer_h_21_INCLASS_NO_PURE_DECLS \
	Project_Source_Project_TwinStickShooterPlayer_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_API UClass* StaticClass<class ATwinStickShooterPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project_Source_Project_TwinStickShooterPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
