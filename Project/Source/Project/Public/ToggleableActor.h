// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ToggleableActor.generated.h"

UCLASS()
class PROJECT_API AToggleableActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AToggleableActor();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMesh;
	UFUNCTION(BlueprintCallable)
		void Toggle();
};
