// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT_PRJPawn_generated_h
#error "PRJPawn.generated.h already included, missing '#pragma once' in PRJPawn.h"
#endif
#define PROJECT_PRJPawn_generated_h

#define Project_Source_Project_Public_PRJPawn_h_12_SPARSE_DATA
#define Project_Source_Project_Public_PRJPawn_h_12_RPC_WRAPPERS
#define Project_Source_Project_Public_PRJPawn_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define Project_Source_Project_Public_PRJPawn_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPRJPawn(); \
	friend struct Z_Construct_UClass_APRJPawn_Statics; \
public: \
	DECLARE_CLASS(APRJPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project"), NO_API) \
	DECLARE_SERIALIZER(APRJPawn)


#define Project_Source_Project_Public_PRJPawn_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAPRJPawn(); \
	friend struct Z_Construct_UClass_APRJPawn_Statics; \
public: \
	DECLARE_CLASS(APRJPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project"), NO_API) \
	DECLARE_SERIALIZER(APRJPawn)


#define Project_Source_Project_Public_PRJPawn_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APRJPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APRJPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APRJPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APRJPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APRJPawn(APRJPawn&&); \
	NO_API APRJPawn(const APRJPawn&); \
public:


#define Project_Source_Project_Public_PRJPawn_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APRJPawn(APRJPawn&&); \
	NO_API APRJPawn(const APRJPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APRJPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APRJPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APRJPawn)


#define Project_Source_Project_Public_PRJPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Cube() { return STRUCT_OFFSET(APRJPawn, Cube); }


#define Project_Source_Project_Public_PRJPawn_h_9_PROLOG
#define Project_Source_Project_Public_PRJPawn_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_Source_Project_Public_PRJPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	Project_Source_Project_Public_PRJPawn_h_12_SPARSE_DATA \
	Project_Source_Project_Public_PRJPawn_h_12_RPC_WRAPPERS \
	Project_Source_Project_Public_PRJPawn_h_12_INCLASS \
	Project_Source_Project_Public_PRJPawn_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project_Source_Project_Public_PRJPawn_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_Source_Project_Public_PRJPawn_h_12_PRIVATE_PROPERTY_OFFSET \
	Project_Source_Project_Public_PRJPawn_h_12_SPARSE_DATA \
	Project_Source_Project_Public_PRJPawn_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Project_Source_Project_Public_PRJPawn_h_12_INCLASS_NO_PURE_DECLS \
	Project_Source_Project_Public_PRJPawn_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_API UClass* StaticClass<class APRJPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project_Source_Project_Public_PRJPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
