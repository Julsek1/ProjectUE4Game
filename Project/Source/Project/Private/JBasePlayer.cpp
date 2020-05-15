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

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");

	SpringArm->SetupAttachment(RootComponent);

	//SpringArm->SetWorldRotation(FRotator(0.f, -50.f, 0.f));
	SpringArm->TargetArmLength = 500;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	JumpHeight = 600.f;
}

// Called when the game starts or when spawned
void AJBasePlayer::BeginPlay()
{
	Super::BeginPlay();



	

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

	PlayerInputComponent->BindAxis("MoveUp", this, &AJBasePlayer::MoveUp);
	PlayerInputComponent->BindAxis("MoveRight", this, &AJBasePlayer::MoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AJBasePlayer::Jump);

}

void AJBasePlayer::Landed(const FHitResult & Hit)
{
	DoubleJumpCounter = 0;
}

void AJBasePlayer::DoubleJump()
{
	if (DoubleJumpCounter <= 1) 
	{
		AJBasePlayer::LaunchCharacter(FVector(0,0, JumpHeight), false, true);
		DoubleJumpCounter++;
	}
}

void AJBasePlayer::MoveUp(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AJBasePlayer::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}
