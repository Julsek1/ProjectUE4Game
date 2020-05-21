// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
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
	virtual void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMesh;
	
	float ReloadSpeed;
	int32 AmmoCapacity;//total amount of ammo you can carry for the gun
	int32 CurrentClipAmmo;//Current ammo left in clip
	int32 ClipSize;//Max ammo for the clip
};
