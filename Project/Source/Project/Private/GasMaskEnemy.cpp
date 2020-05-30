// Fill out your copyright notice in the Description page of Project Settings.


#include "GasMaskEnemy.h"

AGasMaskEnemy::AGasMaskEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	WeaponMuzzle->SetupAttachment(RootComponent);
}

void AGasMaskEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Weapon)
	{
		Weapon->Fire(WeaponMuzzle);
	}
}