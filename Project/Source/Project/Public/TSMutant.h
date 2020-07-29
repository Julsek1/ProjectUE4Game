// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParentEnemy.h"
#include "TSMutant.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API ATSMutant : public AParentEnemy
{
	GENERATED_BODY()

public:
	ATSMutant();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float MeleeDamage = 0.05f;
};
