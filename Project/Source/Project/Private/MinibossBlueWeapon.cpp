// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossBlueWeapon.h"

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "../ParentPlayer.h"
#include "DamageableActor.h"

AMinibossBlueWeapon::AMinibossBlueWeapon()
{
	WeaponName = "Miniboss Blue Sniper";
	Range = 2500.f;
	ClipSize = 4;
	CurrentClipAmmo = ClipSize;
	AmmoCapacity = 1024;
	ReloadSpeed = 3.f;
	FireRate = 2.33f;
	Damage = 0.33f;
}

void AMinibossBlueWeapon::Fire(USceneComponent* Location)
{
	if (Super::CanTheWeaponFire())
	{
		Super::Fire();
		//FHitResult OutHit;
		TArray<FHitResult> OutHits;
		//FVector Start = GetActorLocation();
		FVector Start = Location->GetComponentLocation();
		//FVector Start = GetWorld()->GetFirstPlayerController()->GetCharacter()->GetActorLocation();
		//FVector ForwardVector = GetActorForwardVector();
		FVector ForwardVector = Location->GetForwardVector();
		//FVector ForwardVector = GetWorld()->GetFirstPlayerController()->GetCharacter()->GetActorForwardVector();

		FVector End = ForwardVector * Range + Start;
		FCollisionQueryParams CollisionParams;

		//DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.1f, 0, 1);
		//GetWorld()->LineTraceSingleByChannel(OUT OutHit, Start, End, ECollisionChannel(ECC_Pawn), CollisionParams);
		GetWorld()->LineTraceMultiByChannel(OutHits, Start, End, ECollisionChannel(ECC_Pawn), CollisionParams);

		if (OutHits.Num() > 0 && Cast<AParentPlayer>(OutHits[0].GetActor()))
		{
			//OutHit.GetActor()->Destroy();
			Cast<AParentPlayer>(OutHits[0].GetActor())->GetHit(Damage);
		}
	}
}