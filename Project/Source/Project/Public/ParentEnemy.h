// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/WidgetComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"

#include "ParentEnemy.generated.h"


UCLASS()
class PROJECT_API AParentEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AParentEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite)
		float Health = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UWidgetComponent* WidgetComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString EnemyName;

	//Death
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsDead = false;
	FTimerHandle DeathDespawnTimerHandle;
	void Despawn();
	float TimeToDespawn = 1.5f;

	//Stun
	UFUNCTION(BlueprintCallable)
		virtual void GetStunned();
	void PurgeStun();
	float StunDuration = 0.5f;
	FTimerHandle StunTimerHandle;
	UPROPERTY(BlueprintReadOnly)
		bool bIsStunned = false;
	FTimerHandle StunCooldownTimerHandle;
	float StunCooldown = 2.f;
	bool bStunnedRecently = false;
	void StunCooldownElapsed();
};
