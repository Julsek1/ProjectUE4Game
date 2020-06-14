// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParentEnemy.h"
#include "Miniboss.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMiniboss : public AParentEnemy
{
	GENERATED_BODY()
	
public:
	AMiniboss();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DesiredMovementSpeed = 500.f;
};
