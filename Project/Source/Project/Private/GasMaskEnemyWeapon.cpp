// Fill out your copyright notice in the Description page of Project Settings.


#include "GasMaskEnemyWeapon.h"

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "../ParentPlayer.h"

AGasMaskEnemyWeapon::AGasMaskEnemyWeapon()
{
	WeaponName = "Gas Mask Assault Rifle";
	Range = 1500.f;
	ClipSize = 16;
	CurrentClipAmmo = ClipSize;
	AmmoCapacity = 256;
	ReloadSpeed = 1.5f;
	FireRate = 0.15f;
	Damage = 0.01f;
}

void AGasMaskEnemyWeapon::Fire(USceneComponent* Location)
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

		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.1f, 0, 1);
		//GetWorld()->LineTraceSingleByChannel(OUT OutHit, Start, End, ECollisionChannel(ECC_Pawn), CollisionParams);
		GetWorld()->LineTraceMultiByChannel(OutHits, Start, End, ECollisionChannel(ECC_Vehicle), CollisionParams);

		if (OutHits.Num() > 0 && Cast<AParentPlayer>(OutHits[0].GetActor()))
		{
			//OutHit.GetActor()->Destroy();
			Cast<AParentPlayer>(OutHits[0].GetActor())->GetHit(Damage);
		}

		//if (Cast<AParentEnemy>(OutHit.GetActor()))
		//{
		//	//OutHit.GetActor()->Destroy();
		//	Cast<AParentEnemy>(OutHit.GetActor())->Health -= Damage;
		//}
	}
}