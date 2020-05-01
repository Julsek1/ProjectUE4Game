// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/InputComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"

#include "TwinStickShooterPlayer.generated.h"

UCLASS()
class PROJECT_API ATwinStickShooterPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATwinStickShooterPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveForward(float Vertical);

	UFUNCTION()
		void MoveRight(float Horizontal);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCameraComponent* Camera;
};
