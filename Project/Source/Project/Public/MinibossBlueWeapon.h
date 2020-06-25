// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ParentWeapon.h"
#include "MinibossBlueWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMinibossBlueWeapon : public AParentWeapon
{
	GENERATED_BODY()

public:
	AMinibossBlueWeapon();
	void Fire(USceneComponent* Location) override;
};
