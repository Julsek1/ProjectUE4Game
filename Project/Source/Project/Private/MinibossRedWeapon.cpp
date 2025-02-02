// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossRedWeapon.h"
#include "GameFramework/PlayerController.h"
#include "../ParentPlayer.h"

AMinibossRedWeapon::AMinibossRedWeapon()
{
	WeaponName = "Miniboss Red Rocket Launcher";
	Range = 1500.f;//irrelevant for projectile weapons
	ClipSize = 1000;
	CurrentClipAmmo = ClipSize;
	AmmoCapacity = 1000;
	ReloadSpeed = 2.f;
	FireRate = 0.75f;
	Damage = 0.f;//damage is handled by the rocket class
}

void AMinibossRedWeapon::Fire(USceneComponent* Location)
{
	if (Super::CanTheWeaponFire())
	{
		Super::Fire();
		////FHitResult OutHit;
		//TArray<FHitResult> OutHits;
		////FVector Start = GetActorLocation();
		//FVector Start = Location->GetComponentLocation();
		////FVector Start = GetWorld()->GetFirstPlayerController()->GetCharacter()->GetActorLocation();
		////FVector ForwardVector = GetActorForwardVector();
		//FVector ForwardVector = Location->GetForwardVector();
		////FVector ForwardVector = GetWorld()->GetFirstPlayerController()->GetCharacter()->GetActorForwardVector();

		//FVector End = ForwardVector * Range + Start;
		//FCollisionQueryParams CollisionParams;

		////DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.1f, 0, 1);
		////GetWorld()->LineTraceSingleByChannel(OUT OutHit, Start, End, ECollisionChannel(ECC_Pawn), CollisionParams);
		//GetWorld()->LineTraceMultiByChannel(OutHits, Start, End, ECollisionChannel(ECC_Pawn), CollisionParams);

		//if (OutHits.Num() > 0 && Cast<AParentPlayer>(OutHits[0].GetActor()))
		//{
		//	//OutHit.GetActor()->Destroy();
		//	Cast<AParentPlayer>(OutHits[0].GetActor())->Health -= Damage;
		//}

		////if (Cast<AParentEnemy>(OutHit.GetActor()))
		////{
		////	//OutHit.GetActor()->Destroy();
		////	Cast<AParentEnemy>(OutHit.GetActor())->Health -= Damage;
		////}

		if (Rocket)
		{
			FActorSpawnParameters SpawnParams;
			GetWorld()->SpawnActor<ARocket>(Rocket, Location->GetComponentTransform());
		}
	}
}