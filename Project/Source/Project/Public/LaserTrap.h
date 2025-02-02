// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaserTrap.generated.h"

UCLASS()
class PROJECT_API ALaserTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaserTrap();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fight")
	TSubclassOf<UDamageType> DamageTypeClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSystem")
	class UParticleSystemComponent* BasicPSComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	class UBoxComponent* ColliderBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ParticleSystem")
	class UParticleSystem* PSOnOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundFX")
	class USoundCue* SoundFX;

	UPROPERTY(EditAnywhere)
	FVector InitPoint;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = true))
	FVector FinalPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float InterpolationTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float InterpolationSpeed;

	FTimerHandle TimerInterp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	bool IsInterpolating;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hazard")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deactivate")
	bool DisableInGame;

	float Distance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable, Category = "Deactivate")
	void DeactivateLaser();

	UFUNCTION(BlueprintCallable, Category = "Deactivate")
	void ActivateLaser();

	void VectorsChange(FVector& FirstVector, FVector& SecondVector);

	void ToggleInterp();

	

};
