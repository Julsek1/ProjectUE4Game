// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimationAsset.h"
#include "Components/ArrowComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"

#include "ParentWeapon.generated.h"

UCLASS()
class PROJECT_API AParentWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParentWeapon();
	virtual void Fire(USceneComponent* Location);
	void Fire();
	virtual void Reload();
	virtual void ReplenishClip();
	UPROPERTY(BlueprintReadOnly)
		FTimerHandle ReloadTimerHandle;
	UPROPERTY(BlueprintReadWrite)//ReadOnly
		bool bCanShoot = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float Range;
	bool bCurrentlyReloading = false;
	FTimerHandle FireRateTimerHandle;
	void TimeToFireElapsed();
	float Damage;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* SkeletalMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float ReloadSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float FireRate;//time between shots
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 AmmoCapacity;//total amount of ammo you can carry for the gun
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 CurrentClipAmmo;//Current ammo left in clip
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 ClipSize;//Max ammo for the clip
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString WeaponName;
	bool CanTheWeaponFire();
	//istheweaponfiring

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimationAsset* FiringAnimation = nullptr;

private:
	UPROPERTY(EditAnywhere)
		UArrowComponent* ArrowComponent = nullptr;
};
