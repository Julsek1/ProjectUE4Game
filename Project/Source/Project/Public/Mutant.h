// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mutant.generated.h"

UCLASS()
class PROJECT_API AMutant : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMutant();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Hp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float MaxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	bool IsDeseased;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fight")
	float Damage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
		class AAIController* AIController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		class UParticleSystem* TakeHitPS;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		class USoundCue* KnifeHitSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		USoundCue* PunchSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		bool IsDetected;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fight")
		TSubclassOf<UDamageType> DamageTypeClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Fight")
		class UBoxComponent* BoxCollFight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Fight")
		class UAnimMontage* FightMontage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION()
		void FightOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void FightOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable)
		void CollisionActive();

	UFUNCTION(BlueprintCallable)
		void CollisionInactive();

};
