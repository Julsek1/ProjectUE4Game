// Fill out your copyright notice in the Description page of Project Settings.


#include "GasMaskEnemy.h"

AGasMaskEnemy::AGasMaskEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	WeaponMuzzle->SetupAttachment(RootComponent);

	EnemyName = "Soldier";
}

void AGasMaskEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*if (Weapon)
	{
		if (Weapon->CurrentClipAmmo > 0)
		{
			Fire();
		}

		else
		{
			Reload();
		}
	}*/
}

void AGasMaskEnemy::Fire()
{
	Weapon->Fire(WeaponMuzzle);
}

void AGasMaskEnemy::Reload()
{
	Weapon->Reload();

}