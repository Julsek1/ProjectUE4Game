// Fill out your copyright notice in the Description page of Project Settings.


#include "Rocket.h"
#include "DamageType_Enemy.h"
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
	if (!Cast<AParentEnemy>(Other))
	{
		Explode();
	}
}

void ARocket::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& hit)
{
	Explode();
}

void ARocket::Explode()
{
	TArray<AActor*> Ignore;
	UGameplayStatics::ApplyRadialDamage(GetWorld(), BlastDamage, GetActorLocation(), BlastRadius, UDamageType_Enemy::StaticClass(), Ignore, this, UGameplayStatics::GetPlayerController(this, 0), true, ECollisionChannel(ECC_Pawn));
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, GetActorLocation(), GetActorRotation());
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());

	Destroy();
}