// Fill out your copyright notice in the Description page of Project Settings.


#include "Mutant.h"
#include "JBasePlayer.h"
#include "Animation/AnimInstance.h"

// Sets default values
AMutant::AMutant()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Hp = 90.f;
	MaxHp = 100.f;
	Damage = 20.f;

	IsDeseased = false;

}

// Called when the game starts or when spawned
void AMutant::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMutant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMutant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMutant::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{

	if (Hp - DamageAmount <= 0.f)
	{
		//Hp -= DamageAmount;
		Hp = 0.f;
		
	}
	else
	{
		Hp -= DamageAmount;
		
	}
	return DamageAmount;
}



