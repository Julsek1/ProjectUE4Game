
// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyPickup.h"
#include "../TwinStickShooterPlayer.h"


// Sets default values
AKeyPickup::AKeyPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = Collider;
	StaticMesh->SetupAttachment(Collider);
}

// Called when the game starts or when spawned
//void AKeyPickup::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}

// Called every frame
//void AKeyPickup::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//}

void AKeyPickup::NotifyActorBeginOverlap(AActor* Other)
{
	auto Player = Cast<ATwinStickShooterPlayer>(Other);

	if (Player != nullptr)
	{
		Destroy();
	}
}