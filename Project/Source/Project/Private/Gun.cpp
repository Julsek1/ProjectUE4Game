// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Engine/SkeletalMeshSocket.h"
#include "JBasePlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Engine/SkeletalMeshSocket.h"
#include "JFollowEnemy.h"
#include "Mutant.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"

AGun::AGun()
{
	SkMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkMesh"));
	SkMesh->SetupAttachment(GetRootComponent());

	FightColl = CreateDefaultSubobject<UBoxComponent>(TEXT("FightCollision"));
	FightColl->SetupAttachment(GetRootComponent());

	

	GunState = EGunState::EGS_Take;

	Damage = 15.f;
}

void AGun::BeginPlay()
{
	Super::BeginPlay();

	FightColl->OnComponentBeginOverlap.AddDynamic(this, &AGun::FightOnOverlapBegin);
	FightColl->OnComponentEndOverlap.AddDynamic(this, &AGun::FightOnOverlapEnd);
	
	FightColl->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	FightColl->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	FightColl->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	FightColl->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	
	
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
		SetInstr(Player->GetController());
		//Avoid camera zooming in when the gun is in the way
		SkMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
		SkMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

		SkMesh->SetSimulatePhysics(false);

		const USkeletalMeshSocket* RHand = Player->GetMesh()->GetSocketByName("RightHandSocket");
		if (RHand)
		{
			RHand->AttachActor(this, Player->GetMesh());
			Rotation = false;
			
			
			Player->SetGunEquipped(this);
			Player->SetOverlapedPickup(nullptr);

		}
		if (UseWeaponSound) UGameplayStatics::PlaySound2D(this, UseWeaponSound);
		
	}

}

void AGun::FightOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		//AJFollowEnemy* Enemy = Cast<AJFollowEnemy>(OtherActor);
		AMutant* Enemy = Cast<AMutant>(OtherActor);
		if (Enemy)
		{
			if (Enemy->TakeHitPS)
			{
				const USkeletalMeshSocket* KnifeSocket = SkMesh->GetSocketByName("KnifeSocket");
				if (KnifeSocket)
				{
					FVector LocOfSocket = KnifeSocket->GetSocketLocation(SkMesh);
					UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Enemy->TakeHitPS, LocOfSocket, FRotator(0.f), false);

				}
			}
			if (Enemy->KnifeHitSound)
			{
				UGameplayStatics::PlaySound2D(this, Enemy->KnifeHitSound);
			}
			if (DamageTypeClass)
			{
				UGameplayStatics::ApplyDamage(Enemy, Damage, GunInstr, this, DamageTypeClass);
			}
			
		}
	}
}

void AGun::FightOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}



void AGun::CollActive()
{
	FightColl->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

}

void AGun::CollInactive()
{
	FightColl->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}
