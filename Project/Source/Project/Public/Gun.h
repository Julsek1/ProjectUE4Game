// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePickup.h"
#include "Gun.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AGun : public ABasePickup
{
	GENERATED_BODY()
public:
	AGun();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SkMesh")
	class USkeletalMeshComponent* SkMesh;


	
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	void UseGun(class AJBasePlayer* Player);
	
};
