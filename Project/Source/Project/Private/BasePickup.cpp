// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePickup.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Engine/World.h"
#include "Sound/SoundCue.h"
#include "Kismet/GamePlayStatics.h"


// Sets default values
ABasePickup::ABasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ColliderSphere = CreateDefaultSubobject<USphereComponent>(TEXT("ColliderSphere"));
	RootComponent = ColliderSphere;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

	BasicPSComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BasicPS"));
	BasicPSComponent->SetupAttachment(GetRootComponent());
	
	Rotation = false;
	RotValue = 40.f;

}

// Called when the game starts or when spawned
void ABasePickup::BeginPlay()
{
	Super::BeginPlay();

	ColliderSphere->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::OnOverlapBegin);
	ColliderSphere->OnComponentEndOverlap.AddDynamic(this, &ABasePickup::OnOverlapEnd);
	
}

// Called every frame
void ABasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Rotation)
	{
		FRotator RotMovement = GetActorRotation();
		RotMovement.Yaw += DeltaTime * RotValue;
		SetActorRotation(RotMovement);
	}

}

void ABasePickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (BasicPSComponent)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PSOverlap, GetActorLocation(), FRotator(0.f), true);
		
	}
	if (SoundFX)
	{
		UGameplayStatics::PlaySound2D(this, SoundFX);
	}
	
}

void ABasePickup::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

