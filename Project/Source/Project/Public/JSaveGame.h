// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "JSaveGame.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FPlayerStats
{
	GENERATED_BODY()


	UPROPERTY(VisibleAnywhere, Category = "SavedData")
	float Hp;

	UPROPERTY(VisibleAnywhere, Category = "SavedData")
	float MaxHp;

	UPROPERTY(VisibleAnywhere, Category = "SavedData")
	int32 Collectibles;

	UPROPERTY(VisibleAnywhere, Category = "SavedData")
	FVector PlayerLocation;

	UPROPERTY(VisibleAnywhere, Category = "SavedData")
	FRotator PlayerRotation;

};

UCLASS()
class PROJECT_API UJSaveGame : public USaveGame
{
	GENERATED_BODY()
public:

	UJSaveGame();

	UPROPERTY(VisibleAnywhere, Category = "Basic")
	FString NameOfPlayer;

	UPROPERTY(VisibleAnywhere, Category = "Basic")
	uint32 IndexUser;

	UPROPERTY(VisibleAnywhere, Category = "Basic")
	FPlayerStats PlayerStats;
	
};
