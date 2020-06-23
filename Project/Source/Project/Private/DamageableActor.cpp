// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageableActor.h"

// Sets default values
ADamageableActor::ADamageableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = Collider;
	StaticMesh->SetupAttachment(Collider);
}

// Called when the game starts or when spawned
void ADamageableActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADamageableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADamageableActor::GetHit(float Damage)
{
	if (bCanTakeDamage)
	{
		Health -= Damage;

		if (Health <= 0)
		{
			Destroy();
		}
	}
}

float ADamageableActor::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	GetHit(DamageAmount);

	return 0;
}