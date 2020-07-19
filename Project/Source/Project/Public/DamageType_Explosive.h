// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "DamageType_Explosive.generated.h"

/**
 *
 */
UCLASS()
class PROJECT_API UDamageType_Explosive : public UDamageType
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		float Force = 200000.f;
};
