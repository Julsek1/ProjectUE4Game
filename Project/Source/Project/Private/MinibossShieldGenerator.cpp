// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossShieldGenerator.h"

void AMinibossShieldGenerator::BeginPlay()
{
	Super::BeginPlay();
	EnableShield();
}

void AMinibossShieldGenerator::EnableShield()
{
	bShieldEnabled = true;
	bCanTakeDamage = false;
}

void AMinibossShieldGenerator::DisableShield()
{
	bShieldEnabled = false;
	bCanTakeDamage = true;
}