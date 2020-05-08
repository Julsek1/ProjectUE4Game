// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PRJPawn.generated.h"

UCLASS()
class PROJECT_API APRJPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APRJPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	UStaticMeshComponent* Cube;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Floats")
		float Forwardforce;
	UPROPERTY(EditAnywhere, Category = "Floats")
		float Sideforce;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
