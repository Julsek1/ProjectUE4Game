// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Miniboss.h"
#include "GasMaskEnemyWeapon.h"
#include "MinibossYellow.generated.h"

/**
 *
 */
UCLASS()
class PROJECT_API AMinibossYellow : public AMiniboss
{
	GENERATED_BODY()

public:
	AMinibossYellow();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class AMinibossShieldGenerator*> ShieldGenerators;

	UFUNCTION(BlueprintCallable)
		void Fire();
	UFUNCTION(BlueprintCallable)
		void Reload();

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
		AGasMaskEnemyWeapon* AssaultRifle = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* ReloadAnimation = nullptr;

	UPROPERTY(BlueprintReadWrite)
		bool bEnableFiring = false;
};
