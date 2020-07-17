// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePickup.h"
#include "Gun.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EGunState : uint8
{
	EGS_Take UMETA(DisplayName = "TakeGun"),
	EGS_Using UMETA(DisplayName = "UsingGun"),


	EGS_Top UMETA(DisplayName = "Top"),

};


UCLASS()
class PROJECT_API AGun : public ABasePickup
{
	GENERATED_BODY()
public:
	AGun();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pickup")
	EGunState GunState;

	UPROPERTY(EditDefaultsOnly, Category = "Data")
	FString Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SkMesh")
	class USkeletalMeshComponent* SkMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fight")
	class UBoxComponent* FightColl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	class USoundCue* UseWeaponSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	class USoundCue* KnifeSwingSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fight")
	float Damage;

	


	virtual void BeginPlay() override;
	
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	void UseGun(class AJBasePlayer* Player);

	FORCEINLINE void SetGunState(EGunState Status) { GunState = Status; }
	FORCEINLINE EGunState GetGunState() { return GunState; }

	UFUNCTION()
	void FightOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void FightOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
	UFUNCTION(BlueprintCallable)
	void CollActive();

	UFUNCTION(BlueprintCallable)
	void CollInactive();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fight")
	AController* GunInstr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fight")
	TSubclassOf<UDamageType> DamageTypeClass;
	
	FORCEINLINE void SetInstr(AController* Instr) { GunInstr = Instr; }
};
