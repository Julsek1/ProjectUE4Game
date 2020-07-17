// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageableActor.generated.h"

UCLASS()
class PROJECT_API ADamageableActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADamageableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadOnly)
		float Health = 1.f;
	void GetHit(float Damage);
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMesh;
	UPROPERTY(VisibleAnywhere)
		UBoxComponent* Collider;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bCanTakeDamage = true;
};
