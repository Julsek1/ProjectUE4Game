// Fill out your copyright notice in the Description page of Project Settings.


#include "JBasePlayer.h"
#include "Engine/Engine.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Controller.h"
#include "Gun.h"
#include "Animation/AnimInstance.h"
#include "JSaveGame.h"
#include "Components/SkeletalMeshComponent.h"
#include "..\Public\JBasePlayer.h"
#include "BasePlayerController.h"




// Sets default values
AJBasePlayer::AJBasePlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Create camera's holder
	CameraStick = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraStick"));
	CameraStick->SetupAttachment(GetRootComponent());
	CameraStick->TargetArmLength = 400.f; //camera distance from player
	CameraStick->bUsePawnControlRotation = true; //Rotate according to controller

	//Capsule component size
	GetCapsuleComponent()->SetCapsuleSize(34.f, 95.f);

	//Create player's camera
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(CameraStick, USpringArmComponent::SocketName);
	PlayerCamera->bUsePawnControlRotation = false;

	//Camera's Turn values
	InitialTurnValue = 65.f;
	InitialLookUpValue = 65.f;

	//avoid rotating camera with player rotation
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	//Player movement configuration with rotation rate
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	GetCharacterMovement()->JumpZVelocity = 650.f;
	GetCharacterMovement()->AirControl = 0.2f;

	Hp = 70.f;
	MaxHp = 100.f;
	Collectibles = 0;

	IsEscDown = false;
	IsLeftMouseDown = false;

	IsIDown = false;

	IsFighting = false;

	
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

	PlayerInputComponent->BindAction("EquipItem", IE_Pressed, this, &AJBasePlayer::IDown);
	PlayerInputComponent->BindAction("EquipItem", IE_Released, this, &AJBasePlayer::IUp);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AJBasePlayer::LeftMouseD);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &AJBasePlayer::LeftMouseUp);

	PlayerInputComponent->BindAction("Q", IE_Pressed, this, &AJBasePlayer::EscD);
	PlayerInputComponent->BindAction("Q", IE_Released, this, &AJBasePlayer::EscUp);


	PlayerInputComponent->BindAxis("MoveForward", this, &AJBasePlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AJBasePlayer::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AJBasePlayer::TurnAtUnit);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AJBasePlayer::LookUpAtUnit);
	

}

void AJBasePlayer::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f) && (!IsFighting))
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
	if ((Controller != nullptr) && (Value != 0.0f) && (!IsFighting))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AJBasePlayer::TurnAtUnit(float Value)
{
	AddControllerYawInput(Value* InitialTurnValue* GetWorld()->GetDeltaSeconds());
}

void AJBasePlayer::LookUpAtUnit(float Value)
{
	AddControllerPitchInput(Value * InitialLookUpValue * GetWorld()->GetDeltaSeconds());

}


// Pickup Weapon

void AJBasePlayer::IDown()
{
	IsIDown = true;
	if (OverlapedPickup)
	{
		AGun* Gun = Cast<AGun>(OverlapedPickup);
		if (Gun)
		{
			Gun->UseGun(this);
			SetOverlapedPickup(nullptr);
		}
	}
}

void AJBasePlayer::IUp()
{
	IsIDown = false;
}

// Combat mode

void AJBasePlayer::LeftMouseD()
{
	IsLeftMouseDown = true;
	if (GunEquipped) {


		Fight();
	}
	
}

void AJBasePlayer::LeftMouseUp()
{
	IsLeftMouseDown = false;

}



void AJBasePlayer::EscD()
{
	IsEscDown = true;

	if (PController)
	{
		PController->CheckPMenu();
	}
}

void AJBasePlayer::EscUp()
{
	IsEscDown = false;
}

void AJBasePlayer::Death()
{
}

void AJBasePlayer::DamageHp(float Damage)
{
	if (Hp - Damage <= 0.f)
	{
		Hp -= Damage;
		Death();
	}
	else
	{
		Hp -= Damage;
	}
}

void AJBasePlayer::SetGunEquipped(AGun* GunToSet)
{
	if (GunEquipped)
	{
		
		GunEquipped->Destroy();
	}
	GunEquipped = GunToSet;

}

void AJBasePlayer::GoToNextLevel(FName LevelName)
{
	UWorld* LevelWorld = GetWorld();
		if (LevelWorld)
		{
			FString ActualLevel = LevelWorld->GetMapName();
			FName ActualLevelName(*ActualLevel);
			if (ActualLevelName != LevelName)
			{
				UGameplayStatics::OpenLevel(LevelWorld, LevelName);
			}
		}
}

void AJBasePlayer::SaveGame()
{
	UJSaveGame* SaveGameInst = Cast<UJSaveGame>(UGameplayStatics::CreateSaveGameObject(UJSaveGame::StaticClass()));
	SaveGameInst->PlayerStats.Hp = Hp;
	SaveGameInst->PlayerStats.Collectibles = Collectibles;
	SaveGameInst->PlayerStats.MaxHp = MaxHp;

	SaveGameInst->PlayerStats.PlayerLocation = GetActorLocation();
	SaveGameInst->PlayerStats.PlayerRotation = GetActorRotation();

	UGameplayStatics::SaveGameToSlot(SaveGameInst, SaveGameInst->NameOfPlayer, SaveGameInst->IndexUser);

}

void AJBasePlayer::LoadGame(bool Setpos)
{
	UJSaveGame* LoadGameInst = Cast<UJSaveGame>(UGameplayStatics::CreateSaveGameObject(UJSaveGame::StaticClass()));
	LoadGameInst = Cast<UJSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInst->NameOfPlayer, LoadGameInst->IndexUser));

	Hp = LoadGameInst->PlayerStats.Hp;
	MaxHp = LoadGameInst->PlayerStats.MaxHp;
	Collectibles = LoadGameInst->PlayerStats.Collectibles;

	if (Setpos)
	{
		SetActorLocation(LoadGameInst->PlayerStats.PlayerLocation);
		SetActorRotation(LoadGameInst->PlayerStats.PlayerRotation);
	}
}


//Attacking functions 

void AJBasePlayer::Fight()
{
	if (!IsFighting)
	{
		IsFighting = false;

		

		UAnimInstance* AnimationInst = GetMesh()->GetAnimInstance();
		if (AnimationInst && FightMontage)
		{
			 
			
			int32 MontageSection = FMath::RandRange(0, 1);
			switch (MontageSection)
			{
			case 0:

				AnimationInst->Montage_Play(FightMontage, 2.3f);
				AnimationInst->Montage_JumpToSection(FName("Attack1"), FightMontage);

				break;
			case 1:

				AnimationInst->Montage_Play(FightMontage, 2.5f);
				AnimationInst->Montage_JumpToSection(FName("Attack2"), FightMontage);

				break;

			default:
				;
			}

			
		}
	}
}

void AJBasePlayer::FightFinished()
{
	IsFighting = false;
	if (IsLeftMouseDown)
	{
		Fight();
	}
}

void AJBasePlayer::CollectUp(int32 CollectQty)
{
	Collectibles += CollectQty;
}





