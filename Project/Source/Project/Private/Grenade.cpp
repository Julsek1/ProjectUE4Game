// Fill out your copyright notice in the Description page of Project Settings.


#include "Grenade.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ParentEnemy.h"
#include "Perception/AISense_Hearing.h"


// Sets default values
AGrenade::AGrenade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	RootComponent = Collider;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);
	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
}

// Called when the game starts or when spawned
void AGrenade::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(GrenadeFuseTimerHandle, this, &AGrenade::Explode, GrenadeFuseLength, false);
}

void AGrenade::Explode()
{
	GetWorldTimerManager().ClearTimer(GrenadeFuseTimerHandle);

	TArray<TEnumAsByte<EObjectTypeQuery>> Query;
	TArray<AActor*> Ignore;
	TArray<AActor*> OutHits;

	UKismetSystemLibrary::SphereOverlapActors(this, GetActorLocation(), BlastRadius, Query, AParentEnemy::StaticClass(), Ignore, OutHits);

	for (auto Enemy : OutHits)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *Enemy->GetClass()->GetName());

		if (Cast<AParentEnemy>(Enemy))
		{
			FVector Difference = Enemy->GetActorLocation() - /*UGameplayStatics::GetPlayerCharacter(this, 0)->*/GetActorLocation();
			FVector Direction;
			float Length;
			Difference.ToDirectionAndLength(Direction, Length);
			Cast<AParentEnemy>(Enemy)->GetHit(GrenadeDamage, 300000.f, Direction);
		}
	}

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, GetActorLocation(), GetActorRotation());
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());

	UAISense_Hearing::ReportNoiseEvent(this, GetActorLocation(), 1, UGameplayStatics::GetPlayerCharacter(this, 0), 3000, FName("Sound"));

	Destroy();
}

void AGrenade::NotifyActorBeginOverlap(AActor* Other)
{
	if (Cast<AParentEnemy>(Other) != nullptr)
	{
		Explode();
	}
}

void AGrenade::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& hit)
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), GrenadeHitSound, GetActorLocation(), 0.5f);
}


// Called every frame
//void AGrenade::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

