// Fill out your copyright notice in the Description page of Project Settings.


#include "Miniboss.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AMiniboss::AMiniboss()
{
	WeaponMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	WeaponMuzzle->SetupAttachment(RootComponent);

	EnemyName = "Miniboss";
	GetCharacterMovement()->MaxWalkSpeed = DesiredMovementSpeed;

	DamageResistance = 0.5f;
}

void AMiniboss::BeginPlay()
{
	Super::BeginPlay();
	//PlayerTeleportLocation = UGameplayStatics::GetPlayerCharacter(this, 0)->GetActorLocation();
}

void AMiniboss::Destroyed()
{
	if (GetWorld() && GetWorld()->IsGameWorld() && !bDestroyed)
	{
		bDestroyed = true;
		UGameplayStatics::GetPlayerCharacter(this, 0)->SetActorLocation(PlayerTeleportLocation);
	}
}