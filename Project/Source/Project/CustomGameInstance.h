// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UCustomGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	float PlayerHealth = 1.f;
};
