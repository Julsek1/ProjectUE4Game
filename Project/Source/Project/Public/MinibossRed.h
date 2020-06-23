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
	//virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Fire();
	UFUNCTION(BlueprintCallable)
		void Reload();

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
		AMinibossRedWeapon* RocketLauncher = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* ReloadAnimation = nullptr;
};
