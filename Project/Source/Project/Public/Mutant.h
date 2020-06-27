// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mutant.generated.h"

UCLASS()
class PROJECT_API AMutant : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMutant();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Hp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float MaxHp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
