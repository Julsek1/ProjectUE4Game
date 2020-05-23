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
}

void AShotgun::Fire(USceneComponent* Location)
{
	if (Super::CanTheWeaponFire())
	{
		for (int32 i = 0; i < Pellets; i++)
		{
			FHitResult OutHit;
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
			GetWorld()->LineTraceSingleByChannel(OUT OutHit, Start, End, ECollisionChannel(ECC_Pawn), CollisionParams);

			if (Cast<AParentEnemy>(OutHit.GetActor()))
			{
				OutHit.GetActor()->Destroy();
				UE_LOG(LogTemp, Warning, TEXT("Hit Enemy!"));
			}

		}

	}



}