// Fill out your copyright notice in the Description page of Project Settings.


#include "Mutant.h"
#include "JBasePlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/BoxComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "AIController.h"
#include "Animation/AnimInstance.h"

// Sets default values
AMutant::AMutant()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollFight = CreateDefaultSubobject<UBoxComponent>(TEXT("FightCollision"));
	BoxCollFight->SetBoxExtent(FVector(6.f, 6.f, 6.f));
	//BoxCollFight->SetBoundsScale(0.16f);

	// Socket fix
	BoxCollFight->SetupAttachment(GetMesh(), FName("RFArmSocket"));

	Hp = 90.f;
	MaxHp = 100.f;
	Damage = 20.f;

	IsDeseased = false;

}

// Called when the game starts or when spawned
void AMutant::BeginPlay()
{
	Super::BeginPlay();

	BoxCollFight->OnComponentBeginOverlap.AddDynamic(this, &AMutant::FightOnOverlapBegin);
	BoxCollFight->OnComponentEndOverlap.AddDynamic(this, &AMutant::FightOnOverlapEnd);

	BoxCollFight->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxCollFight->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	BoxCollFight->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxCollFight->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	
}

// Called every frame
void AMutant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMutant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMutant::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{

	if (Hp - DamageAmount <= 0.f)
	{
		//Hp -= DamageAmount;
		Hp = 0.f;
		
	}
	else
	{
		
		Hp -= DamageAmount;
		
	}
	return DamageAmount;
}


void AMutant::FightOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		if (Player)
		{
			if (Player->TakeHitPS)
			{
				const USkeletalMeshSocket* FingerSocket = GetMesh()->GetSocketByName("FingerSocket");
				if (FingerSocket)
				{
					FVector LocOfSocket = FingerSocket->GetSocketLocation(GetMesh());
					UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Player->TakeHitPS, LocOfSocket, FRotator(0.f), false);

				}
			}
			if (Player->DamageSound)
			{
				UGameplayStatics::PlaySound2D(this, Player->DamageSound);
			}
			if (DamageTypeClass)
			{
				UGameplayStatics::ApplyDamage(Player, Damage, AIController, this, DamageTypeClass);
			}
		}
	}
}

void AMutant::FightOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AMutant::CollisionActive()
{
	BoxCollFight->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AMutant::CollisionInactive()
{
	BoxCollFight->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}