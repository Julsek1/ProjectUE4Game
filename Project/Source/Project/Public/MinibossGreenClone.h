// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MinibossGreen.h"
#include "MinibossGreenClone.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMinibossGreenClone : public AMinibossGreen
{
	GENERATED_BODY()

public:
		AMinibossGreenClone();
		virtual void BeginPlay() override;
};
