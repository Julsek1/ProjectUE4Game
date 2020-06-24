// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossYellow.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

AMinibossYellow::AMinibossYellow()
{
	Color = FColor::Yellow;
}

void AMinibossYellow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bEnableFiring)
	{
		if (AssaultRifle->CurrentClipAmmo > 0)
		{
			Fire();

			if (AssaultRifle->bCanShoot)
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
}

void AMinibossYellow::Fire()
{
	if (AssaultRifle)
	{
		AssaultRifle->Fire(WeaponMuzzle);
	}
}

void AMinibossYellow::Reload()
{
	if (AssaultRifle)
	{
		if (AssaultRifle->CanTheWeaponReload())
		{
			if (ReloadAnimation)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(ReloadAnimation, ReloadAnimation->SequenceLength / AssaultRifle->ReloadSpeed);
			}
		}
		AssaultRifle->Reload();
	}
}