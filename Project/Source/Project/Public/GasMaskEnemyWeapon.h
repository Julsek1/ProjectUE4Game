// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ParentWeapon.h"
#include "GasMaskEnemyWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AGasMaskEnemyWeapon : public AParentWeapon
{
	GENERATED_BODY()
public:
	AGasMaskEnemyWeapon();
	void Fire(USceneComponent* Location) override;
};
