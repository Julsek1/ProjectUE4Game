// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePickup.h"
#include "Collectable.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API ACollectable : public ABasePickup
{
	GENERATED_BODY()
public:

	ACollectable();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectibles")
	int32 CollectCount;


	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult) override;


	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	
};
