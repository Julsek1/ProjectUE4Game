// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ParentWeapon.h"
#include "AssaultRifle.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AAssaultRifle : public AParentWeapon
{
	GENERATED_BODY()
public:
	AAssaultRifle();
	void Fire(USceneComponent* Location) override;
};
