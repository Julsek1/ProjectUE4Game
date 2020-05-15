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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Landed(const FHitResult & Hit) override;

	//UPROPERTIES

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float JumpHeight;

	UPROPERTY()
		int DoubleJumpCounter;


	//UFUNCTIONS

	UFUNCTION()
		void DoubleJump();


	//Movement
	void MoveUp(float Value);
	void MoveRight(float Value);
	
};
