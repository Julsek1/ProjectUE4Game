// Fill out your copyright notice in the Description page of Project Settings.


#include "JBasePlayer.h"
#include "Engine/Engine.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Controller.h"
#include "Gun.h"
#include "Engine.h"
#include "Sound/SoundCue.h"
#include "PickupVault.h"
#include "JFollowEnemy.h"
#include "Animation/AnimInstance.h"
#include "JSaveGame.h"
#include "Kismet/KismetMathLibrary.h"
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

	//Stealth
	SKillBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SKillBox"));
	SKillBox->SetupAttachment(GetCapsuleComponent());



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
	/*GetCharacterMovement()->JumpZVelocity = 650.f;*/
	GetCharacterMovement()->AirControl = 0.2f;

	IsDead = false;
	IsWithFightGoal = false;

	Hp = 70.f;
	MaxHp = 100.f;
	Collectibles = 0;

	IsEscDown = false;
	IsLeftMouseDown = false;

	IsFighting = false;

	IsAnnexed = false;
	AnnexPace = 16.f;

	//StealthKill

	IsIDown = false;

	IsKDown = false;

	CanKill = false;

	CanPerformKill = false;

	IsKilling = false;
	
}




// Called when the game starts or when spawned
void AJBasePlayer::BeginPlay()
{
	Super::BeginPlay();
	
	SKillBox->OnComponentBeginOverlap.AddDynamic(this, &AJBasePlayer::SKillBoxOnOverlapBegin);
	SKillBox->OnComponentEndOverlap.AddDynamic(this, &AJBasePlayer::SKillBoxOnOverlapEnd);

	
	SKillBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);



}

// Called every frame
void AJBasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsAnnexed && FightGoal)
	{
		FRotator Sight = GetSightTurning(FightGoal->GetActorLocation());
		
	// Smooth transition while turning player towards goal
       FRotator AnnexTurning = FMath::RInterpTo(GetActorRotation(), Sight, DeltaTime, AnnexPace);

	   SetActorRotation(AnnexTurning);
	}
}

FRotator AJBasePlayer::GetSightTurning(FVector Goal)
{
	FRotator SightTurning = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Goal);
	FRotator GetSightTurning(0.f, SightTurning.Yaw, 0.f);
	return GetSightTurning;
}

// Called to bind functionality to input
void AJBasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	/*PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AJBasePlayer::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AJBasePlayer::StopJumping);*/

	PlayerInputComponent->BindAction("Kill", IE_Pressed, this, &AJBasePlayer::KDown);
	PlayerInputComponent->BindAction("Kill", IE_Released, this, &AJBasePlayer::KUp);

	PlayerInputComponent->BindAction("Crouching", IE_Pressed, this, &AJBasePlayer::CrouchBegin);
	PlayerInputComponent->BindAction("Crouching", IE_Released, this, &AJBasePlayer::CrouchEnd);

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
	if ((Controller != nullptr) && (Value != 0.0f) && (!IsFighting) && (!IsDead))
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
	if ((Controller != nullptr) && (Value != 0.0f) && (!IsFighting) && (!IsDead))
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
	IsFighting = false;
	

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
	UAnimInstance* AnimationInst = GetMesh()->GetAnimInstance();
	if (AnimationInst && FightMontage)
	{
		AnimationInst->Montage_Play(FightMontage, 1.2f);
		AnimationInst->Montage_JumpToSection(FName("Death"));
	}
	IsDead = true;
}

void AJBasePlayer::DamageHp(float Damage)
{
	
}

float AJBasePlayer::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (Hp - DamageAmount <= 0.f)
	{
		Hp -= DamageAmount;
		Death();

		if (DamageCauser)
		{
			AJFollowEnemy* FEnemy = Cast<AJFollowEnemy>(DamageCauser);
			if (FEnemy)
			{
				FEnemy->IsWithGoal = false;
			}
		}
	}
	else
	{
		Hp -= DamageAmount;
	}
	return DamageAmount;
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

	if (GunEquipped)
	{
		SaveGameInst->PlayerStats.Item = GunEquipped->Name;
	}

	UGameplayStatics::SaveGameToSlot(SaveGameInst, SaveGameInst->NameOfPlayer, SaveGameInst->IndexUser);

}

void AJBasePlayer::LoadGame(bool Setpos)
{
	UJSaveGame* LoadGameInst = Cast<UJSaveGame>(UGameplayStatics::CreateSaveGameObject(UJSaveGame::StaticClass()));
	LoadGameInst = Cast<UJSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInst->NameOfPlayer, LoadGameInst->IndexUser));

	Hp = LoadGameInst->PlayerStats.Hp;
	MaxHp = LoadGameInst->PlayerStats.MaxHp;
	Collectibles = LoadGameInst->PlayerStats.Collectibles;

	if (ItemVault)
	{
		APickupVault* Items =  GetWorld()->SpawnActor<APickupVault>(ItemVault);
		if (Items)
		{
			FString ItemName = LoadGameInst->PlayerStats.Item;
			AGun* ItemtoUse = GetWorld()->SpawnActor<AGun>(Items->InventoryBP[ItemName]);
			ItemtoUse->UseGun(this);
		}
	}


	if (Setpos)
	{
		SetActorLocation(LoadGameInst->PlayerStats.PlayerLocation);
		SetActorRotation(LoadGameInst->PlayerStats.PlayerRotation);
	}
}


//Attacking functions 

void AJBasePlayer::Fight()
{
	if (!IsFighting && !IsDead)
	{
		IsFighting = true;
		SetAnnexEnemy(true);
		
		UAnimInstance* AnimationInst = GetMesh()->GetAnimInstance();
		if (AnimationInst && FightMontage)
		{
			 			
			int32 MontageSection = FMath::RandRange(0, 2);
			switch (MontageSection)
			{
			case 0:

				
				AnimationInst->Montage_Play(FightMontage, 2.0f);
				AnimationInst->Montage_JumpToSection(FName("Attack1"), FightMontage);

				break;
			case 1:

				
				AnimationInst->Montage_Play(FightMontage, 2.0f);
				AnimationInst->Montage_JumpToSection(FName("Attack2"), FightMontage);

				break;

			case 2:

				
				AnimationInst->Montage_Play(FightMontage, 2.0f);
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
	SetAnnexEnemy(false);
	if (IsLeftMouseDown)
	{
		Fight();

	}
}

void AJBasePlayer::KnifeSwingPlaySound()
{
	if (GunEquipped->KnifeSwingSound)
	{
		UGameplayStatics::PlaySound2D(this, GunEquipped->KnifeSwingSound);
	}
}

void AJBasePlayer::PlayerTerminated()
{
	GetMesh()->bPauseAnims = true;
	GetMesh()->bNoSkeletonUpdate = true;
}

void AJBasePlayer::CrouchBegin()
{
	Crouch();
}

void AJBasePlayer::CrouchEnd()
{
	UnCrouch();
}

//void AJBasePlayer::Jump()
//{
//	if (!IsDead)
//	{
//		Super::Jump();
//	}
//}



void AJBasePlayer::CollectUp(int32 CollectQty)
{
	Collectibles += CollectQty;
}

void AJBasePlayer::HpUp(float Quantity)
{
	if (Hp + Quantity >= MaxHp)
	{
		Hp = MaxHp;
	}
	else
	{
		Hp += Quantity;
	}
}


//change direction towards enemy when attacking.
void AJBasePlayer::SetAnnexEnemy(bool Annex)
{
	IsAnnexed = Annex;
}



void AJBasePlayer::FightGoalUpdate()
{
	TArray<AActor*> ActorsOverlapped;
	GetOverlappingActors(ActorsOverlapped, MutantF);

	if (ActorsOverlapped.Num() == 0) return;

	AJFollowEnemy* MutantNear = Cast<AJFollowEnemy>(ActorsOverlapped[0]);
	if (MutantNear)
	{
		FVector Position = GetActorLocation();
		float DistMinimun = (MutantNear->GetActorLocation() - Position).Size();
		for (auto Enemy : ActorsOverlapped)
		{
			AJFollowEnemy* Mutant = Cast<AJFollowEnemy>(Enemy);
			if (Mutant)
			{
				float EnemyDist = (Mutant->GetActorLocation() - Position).Size();
				if (EnemyDist < DistMinimun)
				{
					DistMinimun = EnemyDist;
					MutantNear = Mutant;
				}
			}

		}
		SetFightGoal(MutantNear);
		IsWithFightGoal = true;
	}

}

///Stealth Kill

void AJBasePlayer::SKillBoxOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AJFollowEnemy* Enemy = Cast<AJFollowEnemy>(OtherActor);

		{
			if (Enemy)
			{
				
				float Distance = GetDistanceTo(Enemy);
				if (Distance <= 400) {
					
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("FINISH HIM!!"));
					CanKill = true;
				}
				
			}
		}
	}
}

void AJBasePlayer::SKillBoxOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	CanKill = false;
}

void AJBasePlayer::StealthKill()
{
	
	if (CanKill)
	{
		UAnimInstance* AnimationInst = GetMesh()->GetAnimInstance();
		AnimationInst->Montage_JumpToSection(FName("SKill"), FightMontage);
	}
}

void AJBasePlayer::KUp()
{
	IsKDown = false;
	CanPerformKill = false;
	
}
	

void AJBasePlayer::KDown()
{
	
	IsKDown = true;
	if (IsKDown && CanKill) {

		CanPerformKill = true;
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("K"));
	//StealthKill();
}



