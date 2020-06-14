// Fill out your copyright notice in the Description page of Project Settings.


#include "Miniboss.h"

#include "GameFramework/CharacterMovementComponent.h"

AMiniboss::AMiniboss()
{
	EnemyName = "Miniboss";
	GetCharacterMovement()->MaxWalkSpeed = DesiredMovementSpeed;

	DamageResistance = 0.5f;
}