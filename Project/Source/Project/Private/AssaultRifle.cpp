// Fill out your copyright notice in the Description page of Project Settings.


#include "AssaultRifle.h"

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "ParentEnemy.h"
#include "DamageableActor.h"

AAssaultRifle::AAssaultRifle()
{
	WeaponName = "Assault Rifle";
	Range = 1500.f;
	ClipSize = 32;
	CurrentClipAmmo = ClipSize;
	AmmoCapacity = 256;
	ReloadSpeed = 1.f;
	FireRate = 0.1f;
	Damage = 0.1f;
}

void AAssaultRifle::Fire(USceneComponent* Location)
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
		GetWorld()->LineTraceMultiByChannel(OutHits, Start, End, ECollisionChannel(ECC_Vehicle), CollisionParams);

		if (OutHits.Num() > 0 && Cast<AParentEnemy>(OutHits[0].GetActor()))
		{
			//OutHit.GetActor()->Destroy();
			FVector Difference = End - Start;
			FVector Direction;
			float Length;
			Difference.ToDirectionAndLength(Direction, Length);

			Cast<AParentEnemy>(OutHits[0].GetActor())->GetHit(Damage, 25000.f, Direction);
		}

		else if (OutHits.Num() > 0 && Cast<ADamageableActor>(OutHits[0].GetActor()))
		{
			Cast<ADamageableActor>(OutHits[0].GetActor())->GetHit(Damage);
		}

	}
}