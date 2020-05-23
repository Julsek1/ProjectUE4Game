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

	FHitResult OutHit;
	//FVector Start = GetActorLocation();
	FVector Start = Location->GetComponentLocation();
	//FVector Start = GetWorld()->GetFirstPlayerController()->GetCharacter()->GetActorLocation();
	//FVector ForwardVector = GetActorForwardVector();
	FVector ForwardVector = Location->GetForwardVector();
	//FVector ForwardVector = GetWorld()->GetFirstPlayerController()->GetCharacter()->GetActorForwardVector();
	FVector End = ForwardVector * Range + Start;
	FCollisionQueryParams CollisionParams;

	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);
	GetWorld()->LineTraceSingleByObjectType(OUT OutHit, Start, End, FCollisionObjectQueryParams(ECC_Visibility), CollisionParams);

	if (Cast<AParentEnemy>(OutHit.GetActor()))
	{
		//Destroy(OutHit.GetActor());
		UE_LOG(LogTemp, Warning, TEXT("Hit Enemy!"));
	}

}