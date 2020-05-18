// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JFollowEnemy.generated.h"

UENUM(BlueprintType)
enum class EFEnemyMoveStat :uint8
{
	FEMS_Idle          UMETA(DeplayName = "Idle"),
	FEMS_MoveToPlayer  UMETA(DeplayName = "MoveToPlayer"),
	FEMS_Attack        UMETA(DeplayName = "Attack"),
	FEMS_Max           UMETA(DeplayName = "DefMax")

};

UCLASS()
class PROJECT_API AJFollowEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJFollowEnemy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	EFEnemyMoveStat EFEnemyMoveStatus;

	FORCEINLINE void SetFEnemyMovStatus(EFEnemyMoveStat Stat) { EFEnemyMoveStatus = Stat;}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
