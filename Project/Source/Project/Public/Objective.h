// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Objective.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AObjective : public AActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		void UpdateProgress();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Progress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Requirement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bComplete;
};
