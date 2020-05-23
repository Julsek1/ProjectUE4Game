// Fill out your copyright notice in the Description page of Project Settings.


#include "ParentWeapon.h"

// Sets default values
AParentWeapon::AParentWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
}

// Called when the game starts or when spawned
void AParentWeapon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AParentWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AParentWeapon::Fire(USceneComponent* Location)
{

}

void AParentWeapon::Fire()
{
	if (CurrentClipAmmo > 0)
	{
		CurrentClipAmmo--;
	}
}

bool AParentWeapon::CanTheWeaponFire()
{
	if (CurrentClipAmmo > 0)
	{
		Fire();
		return true;
	}

	return false;
}
