// Fill out your copyright notice in the Description page of Project Settings.


#include "ParentEnemy.h"

// Sets default values
AParentEnemy::AParentEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AParentEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AParentEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AParentEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

