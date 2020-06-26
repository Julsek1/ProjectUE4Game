// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserTrap.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Engine/World.h"
#include "JBasePlayer.h"
#include "JFollowEnemy.h"
#include "Sound/SoundCue.h"
#include "Kismet/GamePlayStatics.h"

// Sets default values
ALaserTrap::ALaserTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ColliderBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ColliderBox"));
	RootComponent = ColliderBox;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

	BasicPSComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BasicPS"));
	BasicPSComponent->SetupAttachment(GetRootComponent());

	Damage = 30.f;

}

// Called when the game starts or when spawned
void ALaserTrap::BeginPlay()
{
	Super::BeginPlay();

	ColliderBox->OnComponentBeginOverlap.AddDynamic(this, &ALaserTrap::OnOverlapBegin);
	ColliderBox->OnComponentEndOverlap.AddDynamic(this, &ALaserTrap::OnOverlapEnd);
	
}

// Called every frame
void ALaserTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaserTrap::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		AJFollowEnemy* Mutant = Cast<AJFollowEnemy>(OtherActor);

		if (Player || Mutant)
		{
			
				if (BasicPSComponent)
				{
					UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PSOnOverlap, GetActorLocation(), FRotator(0.f), true);

				}
				if (SoundFX)
				{
					UGameplayStatics::PlaySound2D(this, SoundFX);
				}

				UGameplayStatics::ApplyDamage(OtherActor, Damage, nullptr, this, DamageTypeClass);
				Destroy();

				
			}
		}
	}


void ALaserTrap::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

