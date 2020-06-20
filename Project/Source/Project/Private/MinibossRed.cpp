// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossRed.h"

AMinibossRed::AMinibossRed()
{
	Color = FColor::Red;
}

void AMinibossRed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Fire();
}

void AMinibossRed::Fire()
{
	if (RocketLauncher)
	{
		RocketLauncher->Fire(WeaponMuzzle);
	}
}