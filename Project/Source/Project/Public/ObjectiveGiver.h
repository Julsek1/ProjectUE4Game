// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Objective.h"
#include "ObjectiveGiver.generated.h"

UCLASS()
class PROJECT_API AObjectiveGiver : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObjectiveGiver();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& hit) override;
	virtual void NotifyActorBeginOverlap(AActor* Other) override;
	virtual void NotifyActorEndOverlap(AActor* Other) override;

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
		UBoxComponent* Collider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AObjective* Objective = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSeekPlayer = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AObjectiveGiver*> LinkedObjectives;
	void DestroySelfAndLinked();
};
