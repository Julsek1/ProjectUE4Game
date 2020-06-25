// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Miniboss.h"
#include "MinibossBlueWeapon.h"
#include "MinibossBlue.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMinibossBlue : public AMiniboss
{
	GENERATED_BODY()

public:
	AMinibossBlue();

	UFUNCTION(BlueprintCallable)
		void Fire();
	UFUNCTION(BlueprintCallable)
		void Reload();

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
		AMinibossBlueWeapon* Sniper = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* ReloadAnimation = nullptr;
};
