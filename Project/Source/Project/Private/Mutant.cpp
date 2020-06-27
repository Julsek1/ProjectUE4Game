// Fill out your copyright notice in the Description page of Project Settings.


#include "Mutant.h"

// Sets default values
AMutant::AMutant()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Hp = 90.f;
	MaxHp = 100.f;

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

