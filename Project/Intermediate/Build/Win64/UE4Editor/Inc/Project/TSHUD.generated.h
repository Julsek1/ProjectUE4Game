// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT_TSHUD_generated_h
#error "TSHUD.generated.h already included, missing '#pragma once' in TSHUD.h"
#endif
#define PROJECT_TSHUD_generated_h

#define Project_Source_Project_TSHUD_h_16_SPARSE_DATA
#define Project_Source_Project_TSHUD_h_16_RPC_WRAPPERS
#define Project_Source_Project_TSHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define Project_Source_Project_TSHUD_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTSHUD(); \
	friend struct Z_Construct_UClass_UTSHUD_Statics; \
public: \
	DECLARE_CLASS(UTSHUD, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Project"), NO_API) \
	DECLARE_SERIALIZER(UTSHUD)


#define Project_Source_Project_TSHUD_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUTSHUD(); \
	friend struct Z_Construct_UClass_UTSHUD_Statics; \
public: \
	DECLARE_CLASS(UTSHUD, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Project"), NO_API) \
	DECLARE_SERIALIZER(UTSHUD)


#define Project_Source_Project_TSHUD_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTSHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTSHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTSHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTSHUD(UTSHUD&&); \
	NO_API UTSHUD(const UTSHUD&); \
public:


#define Project_Source_Project_TSHUD_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTSHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTSHUD(UTSHUD&&); \
	NO_API UTSHUD(const UTSHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTSHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTSHUD)


#define Project_Source_Project_TSHUD_h_16_PRIVATE_PROPERTY_OFFSET
#define Project_Source_Project_TSHUD_h_13_PROLOG
#define Project_Source_Project_TSHUD_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_Source_Project_TSHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	Project_Source_Project_TSHUD_h_16_SPARSE_DATA \
	Project_Source_Project_TSHUD_h_16_RPC_WRAPPERS \
	Project_Source_Project_TSHUD_h_16_INCLASS \
	Project_Source_Project_TSHUD_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Project_Source_Project_TSHUD_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Project_Source_Project_TSHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	Project_Source_Project_TSHUD_h_16_SPARSE_DATA \
	Project_Source_Project_TSHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Project_Source_Project_TSHUD_h_16_INCLASS_NO_PURE_DECLS \
	Project_Source_Project_TSHUD_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_API UClass* StaticClass<class UTSHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Project_Source_Project_TSHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
