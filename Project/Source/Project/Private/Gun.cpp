// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Engine/SkeletalMeshSocket.h"
#include "JBasePlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/SkeletalMeshComponent.h"

AGun::AGun()
{
	SkMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkMesh"));
	SkMesh->SetupAttachment(GetRootComponent());

	GunState = EGunState::EGS_Take;
}

void AGun::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if ((GunState == EGunState::EGS_Take) &&  OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		if (Player)
		{
			Player->SetOverlapedPickup(this);
		}
	}
}

void AGun::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		if (Player)
		{
			Player->SetOverlapedPickup(nullptr);
		}
	}
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
			
			Player->SetUsedGun(this);
			Player->SetOverlapedPickup(nullptr);

		}
		if (UseWeaponSound)
		{
			UGameplayStatics::PlaySound2D(this, UseWeaponSound);
		}
	}

}
