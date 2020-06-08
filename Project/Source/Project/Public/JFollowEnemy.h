// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JFollowEnemy.generated.h"

UENUM(BlueprintType)
enum class EFEnemyMoveStat :uint8
{
	FEMS_Idle          UMETA(DisplayName = "Idle"),
	FEMS_MoveToPlayer  UMETA(DisplayName = "MoveToPlayer"),
	FEMS_Attack        UMETA(DisplayName = "Attack"),
	FEMS_Death         UMETA(DisplayName = "Death"),
	FEMS_Max           UMETA(DisplayName = "DefMax"),

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
	FORCEINLINE EFEnemyMoveStat GetFEnemyMovStatus() { return EFEnemyMoveStatus; }


	//Sight
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	class UBoxComponent* VisionBox;

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

	FTimerHandle DyingTempo;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fight")
	bool IsFighting;

	// checks if the enemy has a valid goal to continue attacking
	bool IsWithGoal;

	FTimerHandle FightTempo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fight")
	float Delay;

	void EnemeyGhost();

	AJFollowEnemy* Mutant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	class UParticleSystem* TakeHitPS;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	class USoundCue* KnifeHitSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    USoundCue* PunchSound;

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

	/*UFUNCTION()
	void FollowSphereOnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);*/

	UFUNCTION()
		void VisionBoxOnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	
	/*UFUNCTION()
	void FollowSphereOnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);*/

	UFUNCTION()
		void VisionBoxOnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);




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

	bool IsLiving();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

	void Death(AActor* DamageMaker);

	void Fight();

	//At the end of enemy's death animation
	UFUNCTION(BlueprintCallable)
    void EnemyFinished();


	UFUNCTION(BlueprintCallable)
	void FightFinished();


};
