// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GasMaskAIController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AGasMaskAIController : public AAIController
{
	GENERATED_BODY()
public:
	AGasMaskAIController();

	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* PawnToPossess) override;
	virtual void Tick(float DeltaTime) override;
	virtual FRotator GetControlRotation() const override;

	UFUNCTION()
		void OnPawnDetected(const TArray<AActor*> &DetectedPawns);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float AISightRadius = 1500.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float AISightAge = 5.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float AILoseSightRadius = AISightRadius + 500.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float AIFieldOfView = 90.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UAISenseConfig_Sight* SightConfig;

};
