// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Miniboss.h"
#include "MinibossGreenWeapon.h"
#include "MinibossGreen.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMinibossGreen : public AMiniboss
{
	GENERATED_BODY()

public:
	AMinibossGreen();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Fire();
	UFUNCTION(BlueprintCallable)
		void Reload();

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
		AMinibossGreenWeapon* Shotgun = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* ReloadAnimation = nullptr;
};
