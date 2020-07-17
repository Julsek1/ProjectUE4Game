// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ParentWeapon.h"
#include "MinibossGreenWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMinibossGreenWeapon : public AParentWeapon
{
	GENERATED_BODY()

public:
	AMinibossGreenWeapon();
	void Fire(USceneComponent* Location) override;

private:
	int32 Pellets = 8;
};
