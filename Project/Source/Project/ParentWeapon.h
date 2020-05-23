// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ArrowComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ParentWeapon.generated.h"

UCLASS()
class PROJECT_API AParentWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParentWeapon();
	virtual void Fire(USceneComponent* Location);
	virtual void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float Range;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* SkeletalMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float ReloadSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 AmmoCapacity;//total amount of ammo you can carry for the gun
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 CurrentClipAmmo;//Current ammo left in clip
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 ClipSize;//Max ammo for the clip
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString WeaponName;
	bool CanTheWeaponFire();

private:
	UPROPERTY(EditAnywhere)
		UArrowComponent* ArrowComponent = nullptr;
	
};
