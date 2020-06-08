// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"

#include "Grenade.generated.h"

UCLASS()
class PROJECT_API AGrenade : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGrenade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* Collider = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Mesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* ProjectileComponent = nullptr;
	
	FTimerHandle GrenadeFuseTimerHandle;
	void Explode();
	float GrenadeFuseLength = 2.f;
	float GrenadeDamage = 100.f;
	float BlastRadius = 500.f;
	virtual void NotifyActorBeginOverlap(AActor* Other) override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult &hit) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UParticleSystem* Particle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USoundBase* GrenadeHitSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USoundBase* ExplosionSound;
};
