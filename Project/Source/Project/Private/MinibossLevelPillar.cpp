// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossLevelPillar.h"
#include "Kismet/GameplayStatics.h"
#include "ToggleableActor.h"


// Sets default values
AMinibossLevelPillar::AMinibossLevelPillar()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Explosive = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Explosive"));
	RootComponent = StaticMesh;
	//Collider->SetupAttachment(StaticMesh);
	Explosive->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void AMinibossLevelPillar::BeginPlay()
{
	Super::BeginPlay();
	Explosive->SetVisibility(false);
}

// Called every frame
//void AMinibossLevelPillar::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void AMinibossLevelPillar::PlantExplosive()
{
	Explosive->SetVisibility(true);
	bExplosivePlanted = true;

	if (ToggleOff)
	{
		ToggleOff->Toggle();
	}

	if (ToggleOn)
	{
		ToggleOn->Toggle();
	}
}

void AMinibossLevelPillar::Explode()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion, GetActorLocation(), GetActorRotation());
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());
	Destroy();
}
