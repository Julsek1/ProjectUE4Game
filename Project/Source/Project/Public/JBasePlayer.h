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

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fight")
class UParticleSystem* TakeHitPS;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fight")
class USoundCue* DamageSound;

//Camera position in reference to player
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess=true))
 class USpringArmComponent* CameraStick;

 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
 class UCameraComponent* PlayerCamera;

 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Controller")
 class ABasePlayerController* PController;



 //Turning camera values
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
 float InitialTurnValue;
 UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
 float InitialLookUpValue;

 //PLAYER ITEMS

 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
 float Hp;

 UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
 float MaxHp;

 UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
 float MaxHealth;

 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
 int32 Collectibles;




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

	
	// E to equip item

	bool IsIDown;

	void IDown();
	void IUp();

	
	// Left mouse to attack

	bool IsLeftMouseDown;

	void LeftMouseD();
	void LeftMouseUp();




	//Pause Menu ESC variables

	bool IsEscDown;

	void EscD();
	void EscUp();

	
	//Player's death
	void Death();

	//Collectibles++
	void CollectUp(int32 CollectQty);
	
	//Affect Health
	void DamageHp(float Damage);

	FORCEINLINE class USpringArmComponent* GetCameraStick() const { return CameraStick; };
	FORCEINLINE class UCameraComponent* GetPlayerCamera() const { return PlayerCamera; };

	


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pickup")
	class AGun* GunEquipped;

	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	class ABasePickup* OverlapedPickup;

	void SetGunEquipped(AGun* GunToSet);

	
	FORCEINLINE AGun* GetGunEquipped() { return GunEquipped; }


	FORCEINLINE void SetOverlapedPickup(ABasePickup* PickupToSet) { OverlapedPickup = PickupToSet; }


	void GoToNextLevel(FName LevelName);

	UFUNCTION(BlueprintCallable)
	void SaveGame();

	UFUNCTION(BlueprintCallable)
	void LoadGame(bool SetPos);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Animation")
	bool IsFighting;

	void Fight();

	UFUNCTION(BlueprintCallable)
	void FightFinished();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	class UAnimMontage* FightMontage;

	UFUNCTION(BlueprintCallable)
	void KnifeSwingPlaySound();
	
	
};
