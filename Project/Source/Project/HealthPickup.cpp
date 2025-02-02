// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPickup.h"
#include "TwinStickShooterPlayer.h"

// Sets default values
AHealthPickup::AHealthPickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = Collider;
	StaticMesh->SetupAttachment(Collider);

	//Collider->SetSimulatePhysics(true);
}

//// Called when the game starts or when spawned
//void AHealthPickup::BeginPlay()
//{
//	Super::BeginPlay();
//
//}
//
//// Called every frame
//void AHealthPickup::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

//void AHealthPickup::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& hit)
//{
//	if (Cast<ATwinStickShooterPlayer>(Other) != nullptr)
//	{
//		Cast<ATwinStickShooterPlayer>(Other)->Heal(HealingAmount);
//	}
//
//	Destroy();
//}

void AHealthPickup::NotifyActorBeginOverlap(AActor* Other)
{
	auto Player = Cast<ATwinStickShooterPlayer>(Other);

	if (Player != nullptr)
	{
		if (Player->Health != 1)
		{
			Player->Heal(HealingAmount);

			Destroy();
		}
	}

}
