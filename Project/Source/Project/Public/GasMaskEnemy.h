// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ParentEnemy.h"
#include "../ParentWeapon.h"
#include "GasMaskEnemy.generated.h"

/**
 *
 */
UCLASS()
class PROJECT_API AGasMaskEnemy : public AParentEnemy
{
	GENERATED_BODY()

public:
	AGasMaskEnemy();
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AParentWeapon* Weapon = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* WeaponMuzzle = nullptr;
	UFUNCTION(BlueprintCallable)
		void Fire();
	UFUNCTION(BlueprintCallable)
		void Reload();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bDetectedPlayer = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* ReloadAnimation = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DesiredMovementSpeed = 500.f;
};
