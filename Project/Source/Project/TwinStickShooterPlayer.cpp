// Fill out your copyright notice in the Description page of Project Settings.


#include "TwinStickShooterPlayer.h"
#include "Engine/Engine.h"
#include "GameFramework/Controller.h"

// Sets default values
ATwinStickShooterPlayer::ATwinStickShooterPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set up spring arm and camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ATwinStickShooterPlayer::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("We are using TwinStickShooterPlayer"));
	//UE_LOG(LogTemp, Warning, TEXT("Hello"));
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
	//FRotator Direction = Camera->GetComponentRotation();

	//FVector Direction = Camera->GetComponentRotation().Vector;
	//FVector Direction = GetOwner()->GetActorForwardVector();
	//FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);

	//get camera rotation forward vector to use as direction
	FVector Direction = Camera->GetForwardVector();
	AddMovementInput(Direction, Vertical);
}

void ATwinStickShooterPlayer::MoveRight(float Horizontal)
{
	//FVector Direction = GetOwner()->GetActorRightVector();

	//FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	FVector Direction = Camera->GetRightVector();

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

