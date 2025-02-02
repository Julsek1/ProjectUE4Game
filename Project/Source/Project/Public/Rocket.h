// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundBase.h"

#include "Rocket.generated.h"

UCLASS()
class PROJECT_API ARocket : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARocket();
protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* Collider = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Mesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* ProjectileComponent = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UParticleSystem* Particle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USoundBase* ExplosionSound;

	virtual void NotifyActorBeginOverlap(AActor* Other) override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& hit) override;

	void Explode();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BlastRadius = 350.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BlastDamage = 0.2f;

};
