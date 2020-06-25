// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossGreenClone.h"

AMinibossGreenClone::AMinibossGreenClone()
{
	DamageResistance = -1.f;
}

void AMinibossGreenClone::BeginPlay()
{
	Super::BeginPlay();

	if (Shotgun)
	{
		Shotgun->Damage /= 2;
	}

	bShouldTeleportPlayer = false;
}