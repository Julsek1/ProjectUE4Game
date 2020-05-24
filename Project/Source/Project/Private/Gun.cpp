// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Engine/SkeletalMeshSocket.h"
#include "JBasePlayer.h"
#include "Components/SkeletalMeshComponent.h"

AGun::AGun()
{
	SkMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkMesh"));
	SkMesh->SetupAttachment(GetRootComponent());
}

void AGun::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		if (Player)
		{
			UseGun(Player);
		}
	}
}

void AGun::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
}

void AGun::UseGun(AJBasePlayer* Player)
{
	if (Player)
	{
		//Avoid camera zooming in when the gun is in the way
		SkMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
		SkMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

		SkMesh->SetSimulatePhysics(false);

		const USkeletalMeshSocket* RHand = Player->GetMesh()->GetSocketByName("RightHandSocket");
		if (RHand)
		{
			RHand->AttachActor(this, Player->GetMesh());
			Rotation = false;
		}
	}

}
