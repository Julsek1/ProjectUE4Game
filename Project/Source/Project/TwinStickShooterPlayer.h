// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"

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

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		UCameraComponent* Camera = nullptr;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		USpringArmComponent* SpringArm = nullptr;

	UFUNCTION()
		void RotateX(float RotationX);

	UFUNCTION()
		void RotateY(float RotationY);

private:
	float CharacterRotationX = 0.f;
	float CharacterRotationY = 0.f;

	void Rotate();
};
