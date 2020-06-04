// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/ChildActorComponent.h"
#include "Components/InputComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Objective.h"
#include "ParentPlayer.h"
#include "ParentWeapon.h"
#include "Particles/ParticleSystemComponent.h"
#include "TimerManager.h"
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

	//Weapon
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UChildActorComponent* WeaponComponent = nullptr;*/
	UFUNCTION()
		void Fire();
	UFUNCTION()
		void Reload();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* WeaponMuzzle = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AParentWeapon* CurrentWeapon = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AParentWeapon*> Weapons;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* ReloadAnimation = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* FiringAnimation = nullptr;
	void SwapWeapons();
	
	//Laser sight
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UParticleSystemComponent* LaserSight = nullptr;
	void DisableLaserSight(float Duration);
	void EnableLaserSight();
	FTimerHandle LaserSightTimerHandle;

	//Melee
	float MeleeDamage = 0.2f;
	float MeleeRange = 200.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float MeleeCooldown = 0.525f;
	bool bCanMelee = true;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FTimerHandle MeleeTimerHandle;
	UFUNCTION(BlueprintCallable)
		void MeleeAttack();
	void RestoreMelee();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimMontage* MeleeAnimation = nullptr;

private:
	float CharacterRotationX = 0.f;
	float CharacterRotationY = 0.f;
	void Rotate();
	
	bool bIsFiring = false;
	void FireButtonDown();
	void FireButtonUp();
};
