// Fill out your copyright notice in the Description page of Project Settings.


#include "Shotgun.h"

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "ParentEnemy.h"

AShotgun::AShotgun()
{
	Range = 1000.f;
}

void AShotgun::Fire(USceneComponent* Location)
{
	//Super::Fire();
	UE_LOG(LogTemp, Warning, TEXT("POW!"));

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

		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);
		GetWorld()->LineTraceSingleByObjectType(OUT OutHit, Start, End, FCollisionObjectQueryParams(ECC_Pawn), CollisionParams);

		if (Cast<AParentEnemy>(OutHit.GetActor()))
		{
			OutHit.GetActor()->Destroy();
			UE_LOG(LogTemp, Warning, TEXT("Hit Enemy!"));
		}

	}


}