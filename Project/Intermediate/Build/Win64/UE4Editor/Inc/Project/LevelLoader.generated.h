// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT_LevelLoader_generated_h
#error "LevelLoader.generated.h already included, missing '#pragma once' in LevelLoader.h"
#endif
#define PROJECT_LevelLoader_generated_h

#define Project_Source_Project_LevelLoader_h_14_SPARSE_DATA
#define Project_Source_Project_LevelLoader_h_14_RPC_WRAPPERS
#define Project_Source_Project_LevelLoader_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define Project_Source_Project_LevelLoader_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULevelLoader(); \
	friend struct Z_Construct_UClass_ULevelLoader_Statics; \
public: \
	DECLARE_CLASS(ULevelLoader, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project"), NO_API) \
	DECLARE_SERIALIZER(ULevelLoader)


#define Project_Source_Project_LevelLoader_h_14_INCLASS \
private: \
	static void StaticRegisterNativesULevelLoader(); \
	friend struct Z_Construct_UClass_ULevelLoader_Statics; \
public: \
	DECLARE_CLASS(ULevelLoader, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project"), NO_API) \
	DECLARE_SERIALIZER(ULevelLoader)


#define Project_Source_Project_LevelLoader_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULevelLoader(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULevelLoader) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULevelLoader); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULevelLoader); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULevelLoader(ULevelLoader&&); \
	NO_API ULevelLoader(const ULevelLoader&); \
public:


#define Project_Source_Project_LevelLoader_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULevelLoader(ULevelLoader&&); \
	NO_API ULevelLoader(const ULevelLoader&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULevelLoader); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULevelLoader); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULevelLoader)


#define Project_Source_Project_LevelLoader_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Trigger() { return STRUCT_OFFSET(ULevelLoader, Trigger); }


#define Project_Source_Project_LevelLoader_h_11_PROLOG
#define Project_Source_Project_LevelLoader_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_Source_Project_LevelLoader_h_14_PRIVATE_PROPERTY_OFFSET \
	Project_Source_Project_LevelLoader_h_14_SPARSE_DATA \
	Project_Source_Project_LevelLoader_h_14_RPC_WRAPPERS \
	Project_Source_Project_LevelLoader_h_14_INCLASS \
	Project_Source_Project_LevelLoader_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project_Source_Project_LevelLoader_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_Source_Project_LevelLoader_h_14_PRIVATE_PROPERTY_OFFSET \
	Project_Source_Project_LevelLoader_h_14_SPARSE_DATA \
	Project_Source_Project_LevelLoader_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Project_Source_Project_LevelLoader_h_14_INCLASS_NO_PURE_DECLS \
	Project_Source_Project_LevelLoader_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_API UClass* StaticClass<class ULevelLoader>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project_Source_Project_LevelLoader_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
