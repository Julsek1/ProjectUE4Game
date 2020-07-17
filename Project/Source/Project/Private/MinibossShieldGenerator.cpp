// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossShieldGenerator.h"

void AMinibossShieldGenerator::BeginPlay()
{
	Super::BeginPlay();
	EnableShield();
}

void AMinibossShieldGenerator::EnableShield()
{
	bCanTakeDamage = false;
}

void AMinibossShieldGenerator::DisableShield()
{
	bCanTakeDamage = true;

	if (Miniboss)
	{
		Miniboss->DamageResistance = 1.f;
	}
}

void AMinibossShieldGenerator::Destroyed()
{
	if (GetWorld() && GetWorld()->IsGameWorld())
	{
		if (Miniboss)
		{
			Miniboss->DamageResistance = 0.8f;
		}
	}
}