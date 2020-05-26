// Fill out your copyright notice in the Description page of Project Settings.


#include "AssaultRifle.h"

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "ParentEnemy.h"

AAssaultRifle::AAssaultRifle()
{
	WeaponName = "Assault Rifle";
	Range = 1500.f;
	ClipSize = 32;
	CurrentClipAmmo = 32;
	AmmoCapacity = 256;
	ReloadSpeed = 1.f;
	FireRate = 0.1f;
	Damage = 0.05f;
}

void AAssaultRifle::Fire(USceneComponent* Location)
{
	if (Super::CanTheWeaponFire())
	{
		FHitResult OutHit;
		//FVector Start = GetActorLocation();
		FVector Start = Location->GetComponentLocation();
		//FVector Start = GetWorld()->GetFirstPlayerController()->GetCharacter()->GetActorLocation();
		//FVector ForwardVector = GetActorForwardVector();
		FVector ForwardVector = Location->GetForwardVector();
		//FVector ForwardVector = GetWorld()->GetFirstPlayerController()->GetCharacter()->GetActorForwardVector();

		FVector End = ForwardVector * Range + Start;
		FCollisionQueryParams CollisionParams;

		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.1f, 0, 1);
		GetWorld()->LineTraceSingleByChannel(OUT OutHit, Start, End, ECollisionChannel(ECC_Pawn), CollisionParams);

		if (Cast<AParentEnemy>(OutHit.GetActor()))
		{
			//OutHit.GetActor()->Destroy();
			Cast<AParentEnemy>(OutHit.GetActor())->Health -= Damage;
		}
	}
}