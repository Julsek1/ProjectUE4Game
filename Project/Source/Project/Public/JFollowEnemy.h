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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	class USphereComponent* FollowSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
    USphereComponent* AttackSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	class AAIController* AIController;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	bool IsOverlapAttackSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	AJBasePlayer* AttackTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float Hp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float MaxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	class UParticleSystem* TakeHitPS;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	class USoundCue* KnifeHitSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    USoundCue* PunchSound;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Fight")
	class UBoxComponent* BoxCollFight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Fight")
	class UAnimMontage* FightMontage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fight")
	bool IsFighting;

	AJFollowEnemy* Mutant;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void FollowSphereOnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void FollowSphereOnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void AttackSphereOnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void AttackSphereOnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//target class to be replaced with other player classes
	UFUNCTION(BlueprintCallable)
	void MoveToPlayer(class AJBasePlayer* Player);

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

	void Fight();

	UFUNCTION(BlueprintCallable)
	void FightFinished();


};
