// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TSCollectible.generated.h"

UCLASS()
class PROJECT_API ATSCollectible : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATSCollectible();

//protected:
	// Called when the game starts or when spawned
	/*virtual void BeginPlay() override;*/

public:	
	// Called every frame
	/*virtual void Tick(float DeltaTime) override;*/
	virtual void NotifyActorBeginOverlap(AActor* Other) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBoxComponent* Collider;
};
