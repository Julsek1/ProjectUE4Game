// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePickup.h"
#include "Mine.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMine : public ABasePickup
{
	GENERATED_BODY()

public:

	AMine();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fight")
	TSubclassOf<UDamageType> DamageTypeClass;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Defuse")
	class USphereComponent* DefuseSphere;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defuse")
	bool WasDefused;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hazard")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defuse")
	bool IsATrap;

	
	
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
		    const FHitResult& SweepResult) override;

	
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	
};
