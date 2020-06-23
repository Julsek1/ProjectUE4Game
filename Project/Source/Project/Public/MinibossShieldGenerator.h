// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageableActor.h"
#include "Miniboss.h"

#include "MinibossShieldGenerator.generated.h"

/**
 *
 */
UCLASS()
class PROJECT_API AMinibossShieldGenerator : public ADamageableActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AMiniboss* Miniboss = nullptr;
	UFUNCTION(BlueprintCallable)
		void EnableShield();
	UFUNCTION(BlueprintCallable)
		void DisableShield();
	virtual void Destroyed() override;
};
