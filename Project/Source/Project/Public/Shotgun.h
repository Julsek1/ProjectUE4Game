// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ParentWeapon.h"
#include "Shotgun.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AShotgun : public AParentWeapon
{
	GENERATED_BODY()

public:
	void Fire() override;
	
};
