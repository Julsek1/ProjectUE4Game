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
	AShotgun();
	void Fire(USceneComponent* Location) override;
	/*void Reload() override;
	void ReplenishClip() override;*/

private:
	int32 Pellets = 8;

};
