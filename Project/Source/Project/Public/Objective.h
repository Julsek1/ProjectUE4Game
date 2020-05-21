// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Objective.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AObjective : public AInfo
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		void UpdateProgress();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Progress;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Requirement;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bComplete;
};
