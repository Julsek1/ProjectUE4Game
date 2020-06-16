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
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DesiredMovementSpeed = 500.f;

	FVector PlayerTeleportLocation;

	bool bDestroyed = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FColor Color;
};
