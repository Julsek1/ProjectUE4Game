// Fill out your copyright notice in the Description page of Project Settings.


#include "GasMaskEnemy.h"

#include "Animation/AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"


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
	if (bIsStunned)
	{
		GetCharacterMovement()->MaxWalkSpeed = 0.f;
	}

	else
	{
		if (Weapon && bDetectedPlayer)
		{
			if (Weapon->CurrentClipAmmo > 0)
			{
				Fire();

				if (Weapon->bCanShoot)
				{
					GetCharacterMovement()->MaxWalkSpeed = DesiredMovementSpeed;
				}

				else
				{
					GetCharacterMovement()->MaxWalkSpeed = DesiredMovementSpeed / 2;
				}
			}

			else
			{
				Reload();
			}
		}

		else
		{
			GetCharacterMovement()->MaxWalkSpeed = DesiredMovementSpeed;
		}

	}

}

void AGasMaskEnemy::Fire()
{
	if (Weapon)
	{
		Weapon->Fire(WeaponMuzzle);
	}
}

void AGasMaskEnemy::Reload()
{
	if (Weapon)
	{
		if (Weapon->CanTheWeaponReload())
		{
			if (ReloadAnimation)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(ReloadAnimation, ReloadAnimation->SequenceLength / Weapon->ReloadSpeed);
			}
		}

		Weapon->Reload();
	}
}

void AGasMaskEnemy::GetStunned()
{
	Super::GetStunned();
	/*if (Weapon && Weapon->bCurrentlyReloading)
	{
		Weapon->InterruptReload();
	}*/
}