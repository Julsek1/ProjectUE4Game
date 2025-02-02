// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundBase.h"

#include "MinibossLevelPillar.generated.h"


UCLASS()
class PROJECT_API AMinibossLevelPillar : public AInteractableActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMinibossLevelPillar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	void Interact() override;
	/*UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMesh;*/
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Explosive;
	/*UPROPERTY(VisibleAnywhere)
		UBoxComponent* Collider;*/

	//void PlantExplosive();
	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bExplosivePlanted = false;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UParticleSystem* Explosion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USoundBase* ExplosionSound;
	UFUNCTION(BlueprintCallable)
		void Explode();
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class AToggleableActor*> ShortWalls;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AToggleableActor* ToggleOff = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AToggleableActor* ToggleOn = nullptr;
};
