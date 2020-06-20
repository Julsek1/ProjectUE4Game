// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Miniboss.h"
#include "MinibossRedWeapon.h"

#include "MinibossRed.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMinibossRed : public AMiniboss
{
	GENERATED_BODY()
	
public:
	AMinibossRed();
	virtual void Tick(float DeltaTime) override;
	void Fire();

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
		AMinibossRedWeapon* RocketLauncher = nullptr;
};
