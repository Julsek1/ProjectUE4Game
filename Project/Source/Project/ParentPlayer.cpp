// Fill out your copyright notice in the Description page of Project Settings.


#include "ParentPlayer.h"

// Sets default values
AParentPlayer::AParentPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AParentPlayer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AParentPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AParentPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AParentPlayer::Heal(float HealingAmount)
{
	Health += HealingAmount;

	if (Health >= 1)
	{
		Health = 1;
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Health: %f"), Health));
}

void AParentPlayer::GetHit(float Damage)
{
	if (!bDamageImmune && !bGodMode)
	{
		Health -= Damage;
	}
}

float AParentPlayer::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	GetHit(DamageAmount);

	return 0;
}