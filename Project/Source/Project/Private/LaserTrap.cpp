// Fill out your copyright notice in the Description page of Project Settings.


#include "LaserTrap.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "TimerManager.h"
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


	InitPoint = FVector(0.f);
	FinalPoint = FVector(0.f);

	IsInterpolating = false;

	InterpolationTime = 1.0f;
	InterpolationSpeed = 3.0f;

	


}

// Called when the game starts or when spawned
void ALaserTrap::BeginPlay()
{
	Super::BeginPlay();

	if (DisableInGame)
	{
		DeactivateLaser();
	}

	ColliderBox->OnComponentBeginOverlap.AddDynamic(this, &ALaserTrap::OnOverlapBegin);
	ColliderBox->OnComponentEndOverlap.AddDynamic(this, &ALaserTrap::OnOverlapEnd);

	InitPoint = GetActorLocation();
	FinalPoint += InitPoint;

	IsInterpolating = false;

	GetWorldTimerManager().SetTimer(TimerInterp, this, &ALaserTrap::ToggleInterp, InterpolationTime);

	Distance = (FinalPoint - InitPoint).Size();
	
}

// Called every frame
void ALaserTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

	if (IsInterpolating)
	{
		FVector ActualLocation = GetActorLocation();
		FVector Interpolate = FMath::VInterpTo(ActualLocation, FinalPoint, DeltaTime, InterpolationSpeed);

		SetActorLocation(Interpolate);

		float MoveDistance = (GetActorLocation() - InitPoint).Size();

		if (Distance - MoveDistance < 1.f)
		{
			ToggleInterp();
			GetWorldTimerManager().SetTimer(TimerInterp, this, &ALaserTrap::ToggleInterp, InterpolationTime);
			VectorsChange(InitPoint, FinalPoint);
		}
	}

	

}

void ALaserTrap::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		


		if (Player)
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
				

				
			}
		}
	}


void ALaserTrap::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ALaserTrap::DeactivateLaser()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
}

void ALaserTrap::ActivateLaser()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true);
}

void ALaserTrap::VectorsChange(FVector& FirstVector, FVector& SecondVector)
{
	FVector Temp = FirstVector;
	FirstVector = SecondVector;
	SecondVector = Temp;
}

void ALaserTrap::ToggleInterp()
{
	IsInterpolating = !IsInterpolating;
}


