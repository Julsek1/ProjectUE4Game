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


	//Create camera's holder
	CameraStick = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraStick"));
	CameraStick->SetupAttachment(GetRootComponent());
	CameraStick->TargetArmLength = 600.f; //camera distance from player
	CameraStick->bUsePawnControlRotation = true; //Rotate according to controller

	//Create player's camera
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(CameraStick, USpringArmComponent::SocketName);
	PlayerCamera->bUsePawnControlRotation = false;

	//Camera's Turn values
	InitialTurnValue = 65.f;
	InitialLookUpValue = 65.f;

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
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);


	PlayerInputComponent->BindAxis("MoveForward", this, &AJBasePlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AJBasePlayer::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AJBasePlayer::TurnAtUnit);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AJBasePlayer::LookUpAtUnit);



}

void AJBasePlayer::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		//find forward direction
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);

    }
}

void AJBasePlayer::MoveRight(float Value)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Value);

}

void AJBasePlayer::TurnAtUnit(float Value)
{
	AddControllerYawInput(Value* InitialTurnValue* GetWorld()->GetDeltaSeconds());
}

void AJBasePlayer::LookUpAtUnit(float Value)
{
	AddControllerPitchInput(Value * InitialLookUpValue * GetWorld()->GetDeltaSeconds());

}





