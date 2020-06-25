// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossBlue.h"
#include "Animation/AnimInstance.h"

AMinibossBlue::AMinibossBlue()
{
	Color = FColor::Blue;
}

void AMinibossBlue::Fire()
{
	if (Sniper)
	{
		Sniper->Fire(WeaponMuzzle);
	}
}

void AMinibossBlue::Reload()
{
	if (Sniper)
	{
		if (Sniper->CanTheWeaponReload())
		{
			if (ReloadAnimation)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(ReloadAnimation, ReloadAnimation->SequenceLength / Sniper->ReloadSpeed);
			}
		}

		Sniper->Reload();
	}
}