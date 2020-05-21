// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Objective.h"
#include "ParentPlayer.h"
#include "TSHUD.h"

#include "TwinStickShooterPlayer.generated.h"

UCLASS()
class PROJECT_API ATwinStickShooterPlayer : public AParentPlayer
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

	//Player locomotion
	UFUNCTION()
		void MoveForward(float Vertical);
	UFUNCTION()
		void MoveRight(float Horizontal);
	UFUNCTION()
		void RotateX(float RotationX);
	UFUNCTION()
		void RotateY(float RotationY);
	
	//Main camera
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		UCameraComponent* MainCamera = nullptr;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		USpringArmComponent* MainSpringArm = nullptr;

	//Minimap
	/*UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		USceneCaptureComponent2D* MinimapCapture = nullptr;*/
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		USpringArmComponent* MinimapSpringArm = nullptr;

	//HUD
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UTSHUD> HUDClass;


	virtual void Heal(float HealingAmount) override;

	//Objective
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		AObjective* CurrentObjective = nullptr;
	UFUNCTION()
		void ReceiveObjective(AObjective* Objective);

private:
	float CharacterRotationX = 0.f;
	float CharacterRotationY = 0.f;

	void Rotate();
};
