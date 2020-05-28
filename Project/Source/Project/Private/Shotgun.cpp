// Fill out your copyright notice in the Description page of Project Settings.


#include "Shotgun.h"

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "ParentEnemy.h"

AShotgun::AShotgun()
{
	WeaponName = "Shotgun";
	Range = 1000.f;
	ClipSize = 8;
	CurrentClipAmmo = 8;
	AmmoCapacity = 64;
	ReloadSpeed = 2.f;
	FireRate = 0.66f;
	Damage = 0.08f;
}

void AShotgun::Fire(USceneComponent* Location)
{
	if (Super::CanTheWeaponFire())
	{
		for (int32 i = 0; i < Pellets; i++)
		{
			//FHitResult OutHit;
			TArray<FHitResult> OutHits;
			//FVector Start = GetActorLocation();
			FVector Start = Location->GetComponentLocation();
			//FVector Start = GetWorld()->GetFirstPlayerController()->GetCharacter()->GetActorLocation();
			//FVector ForwardVector = GetActorForwardVector();
			FVector ForwardVector = Location->GetForwardVector();
			//FVector ForwardVector = GetWorld()->GetFirstPlayerController()->GetCharacter()->GetActorForwardVector();

			//Get random ranges for shotgun spread
			FVector Spread = FVector(FMath::RandRange(-100.f, 100.f), FMath::RandRange(-100.f, 100.f), FMath::RandRange(-100.f, 100.f));

			FVector End = ForwardVector * Range + Start + Spread;
			FCollisionQueryParams CollisionParams;

			DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.1f, 0, 1);
			GetWorld()->LineTraceMultiByChannel(OutHits, Start, End, ECollisionChannel(ECC_Pawn), CollisionParams);

			for (int32 j = 0; j < OutHits.Num(); j++)
			{
				if (Cast<AParentEnemy>(OutHits[j].GetActor()))
				{
					Cast<AParentEnemy>(OutHits[j].GetActor())->Health -= Damage;
				}
			}

			/*GetWorld()->LineTraceSingleByChannel(OUT OutHit, Start, End, ECollisionChannel(ECC_Pawn), CollisionParams);

			if (Cast<AParentEnemy>(OutHit.GetActor()))
			{
				Cast<AParentEnemy>(OutHit.GetActor())->Health -= Damage;
			}*/

		}

	}
}

//void AShotgun::Reload()
//{
//	if (!bCurrentlyReloading)
//	{
//		bCurrentlyReloading = true;
//
//		GetWorldTimerManager().SetTimer(ReloadTimerHandle, this, &AParentWeapon::ReplenishClip, ReloadSpeed, false);
//	}
//
//}
//
//void AShotgun::ReplenishClip()
//{
//	GetWorldTimerManager().ClearTimer(ReloadTimerHandle);
//
//	while (CurrentClipAmmo < ClipSize && AmmoCapacity > 0)//get rid of while loop once this works
//	{
//		CurrentClipAmmo++;
//		AmmoCapacity--;
//	}
//
//	bCurrentlyReloading = false;
//}