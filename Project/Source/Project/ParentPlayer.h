// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ParentPlayer.generated.h"

UCLASS()
class PROJECT_API AParentPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AParentPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		virtual void Heal(float HealingAmount);
	//Health
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Health = 1.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bDamageImmune = false;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable)
		void GetHit(float Damage);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bGodMode = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bIsDead = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 NumberOfCollectibles = 0;

};
