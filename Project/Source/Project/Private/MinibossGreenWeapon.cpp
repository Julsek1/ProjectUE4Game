// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossGreenWeapon.h"

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "../ParentPlayer.h"
#include "DamageableActor.h"

AMinibossGreenWeapon::AMinibossGreenWeapon()
{
	WeaponName = "Miniboss Green Shotgun";
	Range = 500.f;
	ClipSize = 8;
	CurrentClipAmmo = ClipSize;
	AmmoCapacity = 1024;
	ReloadSpeed = 2.f;
	FireRate = 1.33f;
	Damage = 0.08f;
}

void AMinibossGreenWeapon::Fire(USceneComponent* Location)
{
	if (Super::CanTheWeaponFire())
	{
		Super::Fire();
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
				if (Cast<AParentPlayer>(OutHits[j].GetActor()))
				{
					FVector Difference = End - Start;
					FVector Direction;
					float Length;
					Difference.ToDirectionAndLength(Direction, Length);

					Cast<AParentPlayer>(OutHits[j].GetActor())->GetHit(Damage);
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