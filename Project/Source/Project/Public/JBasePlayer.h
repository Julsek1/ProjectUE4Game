// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "../ParentPlayer.h"
#include "JBasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AJBasePlayer : public AParentPlayer
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJBasePlayer();

//Camera position in reference to player
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess=true))
 class USpringArmComponent* CameraStick;

 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
 class UCameraComponent* PlayerCamera;

 //Turning camera values
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
 float InitialTurnValue;
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
 float InitialLookUpValue;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//forward and backwards movement
	void MoveForward(float Value);
	//side movement
	void MoveRight(float Value);

	//Turn at a provided value
	void TurnAtUnit(float Value);

	//Look up and down at a provided value
	void LookUpAtUnit(float Value);

	FORCEINLINE class USpringArmComponent* GetCameraStick() const { return CameraStick; };
	FORCEINLINE class UCameraComponent* GetPlayerCamera() const { return PlayerCamera; };
	
};
