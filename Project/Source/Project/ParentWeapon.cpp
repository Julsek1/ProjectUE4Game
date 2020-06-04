// Fill out your copyright notice in the Description page of Project Settings.


#include "ParentWeapon.h"

// Sets default values
AParentWeapon::AParentWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));

	WeaponName = "";
	Range = 0.f;
	ClipSize = 0;
	CurrentClipAmmo = ClipSize;
	AmmoCapacity = 0;
	ReloadSpeed = 0.f;
	FireRate = 0.f;
	Damage = 0.f;
}

// Called when the game starts or when spawned
void AParentWeapon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
//void AParentWeapon::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void AParentWeapon::Fire(USceneComponent* Location)
{

}

//void AParentWeapon::Fire()
//{
//	if (CurrentClipAmmo > 0)
//	{
//		CurrentClipAmmo--;
//	}
//
//	//play firing animation
//	if (FiringAnimation)
//	{
//		SkeletalMesh->PlayAnimation(FiringAnimation, false);
//	}
//
//}
//
//bool AParentWeapon::CanTheWeaponFire()
//{
//	if (CurrentClipAmmo > 0 && !bCurrentlyReloading && bCanShoot)
//	{
//		bCanShoot = false;
//		Fire();
//		GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &AParentWeapon::TimeToFireElapsed, FireRate, false);
//		return true;
//	}
//
//	return false;
//}

void AParentWeapon::Fire()
{
	CurrentClipAmmo--;
	bCanShoot = false;
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &AParentWeapon::TimeToFireElapsed, FireRate, false);

	//play firing animation
	if (FiringAnimation)
	{
		SkeletalMesh->PlayAnimation(FiringAnimation, false);
	}
}

bool AParentWeapon::CanTheWeaponFire()
{
	return CurrentClipAmmo > 0 && !bCurrentlyReloading && bCanShoot;
}

void AParentWeapon::TimeToFireElapsed()
{
	GetWorldTimerManager().ClearTimer(FireRateTimerHandle);

	bCanShoot = true;
}

void AParentWeapon::Reload()
{
	if (CanTheWeaponReload())
	{
		bCurrentlyReloading = true;

		GetWorldTimerManager().SetTimer(ReloadTimerHandle, this, &AParentWeapon::ReplenishClip, ReloadSpeed, false);

		if (ReloadingAnimation)
		{
			SkeletalMesh->PlayAnimation(ReloadingAnimation, false);
		}
	}
}

bool AParentWeapon::CanTheWeaponReload()
{
	return !bCurrentlyReloading && AmmoCapacity > 0 && CurrentClipAmmo < ClipSize;
}

void AParentWeapon::ReplenishClip()
{
	GetWorldTimerManager().ClearTimer(ReloadTimerHandle);

	if (ClipSize - CurrentClipAmmo <= AmmoCapacity)
	{
		AmmoCapacity -= (ClipSize - CurrentClipAmmo);
		CurrentClipAmmo = ClipSize;
	}

	else
	{
		CurrentClipAmmo += AmmoCapacity;
		AmmoCapacity = 0;
	}

	//while (CurrentClipAmmo < ClipSize && AmmoCapacity > 0)//get rid of while loop once this works
	//{
	//	CurrentClipAmmo++;
	//	AmmoCapacity--;
	//}

	bCurrentlyReloading = false;
}
