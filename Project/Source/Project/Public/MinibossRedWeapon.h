// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ParentWeapon.h"
#include "MinibossRedWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMinibossRedWeapon : public AParentWeapon
{
	GENERATED_BODY()
public:
	AMinibossRedWeapon();
	void Fire(USceneComponent* Location) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class ARocket> Rocket;
};
