// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoPickup.h"

#include "../TwinStickShooterPlayer.h"

// Sets default values
AAmmoPickup::AAmmoPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = Collider;
	StaticMesh->SetupAttachment(Collider);
}

//// Called when the game starts or when spawned
//void AAmmoPickup::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
//
//// Called every frame
//void AAmmoPickup::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void AAmmoPickup::NotifyActorBeginOverlap(AActor* Other)
{
	auto Player = Cast<ATwinStickShooterPlayer>(Other);

	if (Player != nullptr)
	{
		if (Player->CurrentWeapon->WeaponName == "Shotgun")
		{
			AmmoAmount /= 6;
		}

		Player->CurrentWeapon->AmmoCapacity += AmmoAmount;

		Destroy();
	}
}
