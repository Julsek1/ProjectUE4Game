// Fill out your copyright notice in the Description page of Project Settings.


#include "JBasePlayer.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "GameFramework/Controller.h"

// Sets default values
AJBasePlayer::AJBasePlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AJBasePlayer::BeginPlay()
{
	Super::BeginPlay();

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	

}

// Called every frame
void AJBasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJBasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
