// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossRed.h"

#include "Animation/AnimInstance.h"


AMinibossRed::AMinibossRed()
{
	Color = FColor::Red;
}

//void AMinibossRed::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//	//Fire();
//}

void AMinibossRed::Fire()
{
	if (RocketLauncher)
	{
		RocketLauncher->Fire(WeaponMuzzle);
	}
}

void AMinibossRed::Reload()
{
	if (RocketLauncher)
	{
		if (RocketLauncher->CanTheWeaponReload())
		{
			if (ReloadAnimation)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(ReloadAnimation, ReloadAnimation->SequenceLength / RocketLauncher->ReloadSpeed);
			}
		}
		RocketLauncher->Reload();
	}
}