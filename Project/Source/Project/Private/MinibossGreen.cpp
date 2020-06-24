// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossGreen.h"

#include "Animation/AnimInstance.h"

AMinibossGreen::AMinibossGreen()
{
	Color = FColor::Green;
}

void AMinibossGreen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*Fire();*/
}

void AMinibossGreen::Fire()
{
	if (Shotgun)
	{
		Shotgun->Fire(WeaponMuzzle);
	}
}

void AMinibossGreen::Reload()
{
	if (Shotgun)
	{
		if (Shotgun->CanTheWeaponReload())
		{
			if (ReloadAnimation)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(ReloadAnimation, ReloadAnimation->SequenceLength / Shotgun->ReloadSpeed);
			}
		}

		Shotgun->Reload();
	}
}
