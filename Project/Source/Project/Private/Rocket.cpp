// Fill out your copyright notice in the Description page of Project Settings.


#include "Rocket.h"
#include "DamageType_Explosive.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ParentEnemy.h"

// Sets default values
ARocket::ARocket()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	RootComponent = Collider;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);
	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
}

//// Called when the game starts or when spawned
//void ARocket::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
//
//// Called every frame
//void ARocket::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void ARocket::NotifyActorBeginOverlap(AActor* Other)
{
	UE_LOG(LogTemp, Warning, TEXT("You hit %s"), *Other->GetName());

	if (!Cast<AParentEnemy>(Other))
	{
		Explode();
	}

}

void ARocket::Explode()
{
	TArray<AActor*> Ignore;
	UGameplayStatics::ApplyRadialDamage(GetWorld(), BlastDamage, GetActorLocation(), BlastRadius, UDamageType_Explosive::StaticClass(), Ignore, this, UGameplayStatics::GetPlayerController(this, 0), true, ECollisionChannel(ECC_Pawn));
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, GetActorLocation(), GetActorRotation());
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());

	Destroy();
}