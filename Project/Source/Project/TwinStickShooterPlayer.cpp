// Fill out your copyright notice in the Description page of Project Settings.


#include "TwinStickShooterPlayer.h"
#include "CustomGameInstance.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "GameFramework/Controller.h"

// Sets default values
ATwinStickShooterPlayer::ATwinStickShooterPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup main camera with spring arm
	MainSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MainCameraSpringArm"));
	MainSpringArm->SetupAttachment(RootComponent);
	MainSpringArm->SetWorldRotation(FRotator(330.f, 0.f, 0.f));
	MainSpringArm->TargetArmLength = 1000;
	//MainSpringArm->bUsePawnControlRotation = false;
	MainSpringArm->bInheritPitch = false;
	MainSpringArm->bInheritYaw = false;
	MainSpringArm->bInheritRoll= false;
	MainSpringArm->bDoCollisionTest = false;

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(MainSpringArm, USpringArmComponent::SocketName);
	MainCamera->bUsePawnControlRotation = false;

	//Setup minimap camera and icons
	MinimapSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MinimapSpringArm"));
	MinimapSpringArm->SetupAttachment(RootComponent);
	MinimapSpringArm->SetWorldRotation(FRotator(-90.f, 0.f, 0.f));
	MinimapSpringArm->TargetArmLength = 600;
	MinimapSpringArm->bInheritPitch = false;
	MinimapSpringArm->bInheritYaw = false;
	MinimapSpringArm->bInheritRoll = false;
	MinimapSpringArm->bDoCollisionTest = false;

	/*MinimapCapture->CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("MinimapCapture"));
	MinimapCapture->SetupAttachment(MinimapSpringArm);*/

}

// Called when the game starts or when spawned
void ATwinStickShooterPlayer::BeginPlay()
{
	Super::BeginPlay();

	//Setup values from game instance
	Health = GetWorld()->GetGameInstance<UCustomGameInstance>()->PlayerHealth;

	//Setup HUD
	auto HUD = CreateWidget<UTSHUD>(GetWorld()->GetFirstPlayerController(), HUDClass);
	HUD->Player = this;
	HUD->AddToViewport();

	//Debug messages
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("We are using TwinStickShooterPlayer"));
}

// Called every frame
void ATwinStickShooterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATwinStickShooterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("TSForward", this, &ATwinStickShooterPlayer::MoveForward);
	PlayerInputComponent->BindAxis("TSRight", this, &ATwinStickShooterPlayer::MoveRight);
	PlayerInputComponent->BindAxis("TSRotateX", this, &ATwinStickShooterPlayer::RotateX);
	PlayerInputComponent->BindAxis("TSRotateY", this, &ATwinStickShooterPlayer::RotateY);
}

void ATwinStickShooterPlayer::MoveForward(float Vertical)
{
	FVector Direction = MainCamera->GetForwardVector();

	//Multiplied by 2 because of the camera placement, will have to change if the camera is at a different angle
	AddMovementInput(Direction, Vertical * 2);
}

void ATwinStickShooterPlayer::MoveRight(float Horizontal)
{
	FVector Direction = MainCamera->GetRightVector();

	AddMovementInput(Direction, Horizontal);
}

void ATwinStickShooterPlayer::RotateX(float RotationX)
{
	CharacterRotationX = RotationX;
	Rotate();
}

void ATwinStickShooterPlayer::RotateY(float RotationY)
{
	CharacterRotationY = RotationY;
	Rotate();
}

void ATwinStickShooterPlayer::Rotate()
{
	FVector CharacterVector(CharacterRotationY, CharacterRotationX, 0.f);

	if (CharacterVector.Size() > 0.1)
	{
		FRotator CharacterRotation = CharacterVector.Rotation();
		GetController()->SetControlRotation(CharacterRotation);
	}

}

//void ATwinStickShooterPlayer::TakeDamage(float Damage)
//{
//	Health -= Damage;
//}

void ATwinStickShooterPlayer::Heal(float HealingAmount)
{
	Health += HealingAmount * 2;

	if (Health >= 1)
	{
		Health = 1;
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Health: %f"), Health));
}

void ATwinStickShooterPlayer::ReceiveObjective(AObjective* Objective)
{
	CurrentObjective = Objective;
	/*CurrentObjective->Description = Objective->Description;
	CurrentObjective->Requirement = Objective->Requirement*/;
}
