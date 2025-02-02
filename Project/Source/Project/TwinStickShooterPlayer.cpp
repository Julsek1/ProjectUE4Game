// Fill out your copyright notice in the Description page of Project Settings.


#include "TwinStickShooterPlayer.h"

#include "Animation/AnimInstance.h"
#include "AssaultRifle.h"
#include "CustomGameInstance.h"
#include "DamageType_Melee.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "InteractableActor.h"
#include "JSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
//#include "MinibossLevelPillar.h"
#include "Misc/OutputDeviceNull.h"
#include "ParentEnemy.h"
#include "Perception/AISense_Hearing.h"
//#include "Shotgun.h"
//#include "Grenade.h"


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
	MainSpringArm->bInheritRoll = false;
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

	//SetupWeapon
	/*WeaponComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("Weapon"));
	WeaponComponent->SetupAttachment(GetMesh());*/
	WeaponMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	WeaponMuzzle->SetupAttachment(RootComponent);

	//Setup laser sight
	LaserSight = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("LaserSight"));
	LaserSight->SetupAttachment(GetMesh());

	//Checkpoint
	UJSaveGame* LoadGameInst = Cast<UJSaveGame>(UGameplayStatics::CreateSaveGameObject(UJSaveGame::StaticClass()));
	if (LoadGameInst)
	{
		LoadGameInst = Cast<UJSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInst->NameOfPlayer, LoadGameInst->IndexUser));

		if (LoadGameInst)
		{
			bShouldLoadCheckpoint = LoadGameInst->PlayerStats.LoadCheckpoint;
			//Collectibles = LoadGameInst->PlayerStats.Collectibles;
		}
	}

}

// Called when the game starts or when spawned
void ATwinStickShooterPlayer::BeginPlay()
{
	Super::BeginPlay();

	//Give empty objective
	CurrentObjective = NewObject<AObjective>(this);
	//Grenade = NewObject<AGrenade>(this);
	//Give a weapon
	//Weapons.Add(NewObject<AAssaultRifle>(this));
	//Weapons.Add(NewObject<AShotgun>(this));

	//CurrentWeapon = Weapons[0];

	/*if (Weapons.Num() > 0)
	{
		CurrentWeapon = Weapons[0].GetDefaultObject();
	}*/

	//CurrentWeapon = Weapons[0];

	//Setup values from game instance
	//Health = GetWorld()->GetGameInstance<UCustomGameInstance>()->PlayerHealth;

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

	if (Health <= 0)
	{
		//Load();
		Health = 0;
		bIsDead = true;
	}

	if (GetVelocity() != FVector(0.f, 0.f, 0.f))
	{
		UAISense_Hearing::ReportNoiseEvent(this, GetActorLocation(), 1, this, 300, FName("Sound"));
	}


	//UE_LOG(LogTemp, Warning, TEXT("Max walk speed: %f"), GetCharacterMovement()->GetMaxSpeed());

	if (bIsFiring && bCanMelee && bCanThrowGrenade)
	{
		Fire();

		if (CurrentWeapon)
		{
			if (CurrentWeapon->bCanShoot)
			{
				GetCharacterMovement()->MaxWalkSpeed = 600.f;
			}

			else
			{
				GetCharacterMovement()->MaxWalkSpeed = 300.f;
			}
		}
	}

	else
	{
		GetCharacterMovement()->MaxWalkSpeed = 600.f;
	}

	if (LaserSight)
	{
		TArray<FHitResult> OutHits;
		FVector Start = LaserSight->GetComponentLocation();
		FCollisionQueryParams CollisionParams;
		float LaserSightDistance = CurrentWeapon->Range;

		FVector End = LaserSight->GetForwardVector() * LaserSightDistance + LaserSight->GetComponentLocation();
		GetWorld()->LineTraceMultiByChannel(OutHits, Start, End, ECollisionChannel(ECC_Pawn), CollisionParams);

		if (OutHits.Num() > 0 && OutHits[0].GetActor())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Self: %s"), *WeaponMuzzle->GetForwardVector().ToString());
			//UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *OutHits[0].GetActor()->GetActorLocation().ToString());
			FVector HitActorLocation = OutHits[0].GetActor()->GetActorLocation();
			float HitDistX = FMath::Abs(HitActorLocation.X - Start.X);
			float HitDistY = FMath::Abs(HitActorLocation.Y - Start.Y);
			float DistX = FMath::Abs(WeaponMuzzle->GetForwardVector().X * HitDistX);
			float DistY = FMath::Abs(WeaponMuzzle->GetForwardVector().Y * HitDistY);

			LaserSightDistance = DistX + DistY;
			//LaserSightDistance = ((DistX + DistY) < (HitActorLocation - Start).Size()) ? DistX + DistY : (HitActorLocation - Start).Size();
		}

		End = LaserSight->GetForwardVector() * LaserSightDistance + LaserSight->GetComponentLocation();

		LaserSight->SetBeamSourcePoint(0, Start, 0);
		LaserSight->SetBeamTargetPoint(0, End, 0);
	}

	//look for interactable actor
	/*if (LookForInteractablePillar())
	{
		bFoundInteractablePillar = !LookForInteractablePillar()->bExplosivePlanted;
	}

	else
	{
		bFoundInteractablePillar = false;
	}*/

	//bFoundInteractablePillar = LookForInteractablePillar() != nullptr && !LookForInteractablePillar()->bExplosivePlanted;
	bFoundInteractableActor = LookForInteractableActor() != nullptr && !LookForInteractableActor()->bHasBeenInteractedWith;
}

// Called to bind functionality to input
void ATwinStickShooterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("TSForward", this, &ATwinStickShooterPlayer::MoveForward);
	PlayerInputComponent->BindAxis("TSRight", this, &ATwinStickShooterPlayer::MoveRight);
	PlayerInputComponent->BindAxis("TSRotateX", this, &ATwinStickShooterPlayer::RotateX);
	PlayerInputComponent->BindAxis("TSRotateY", this, &ATwinStickShooterPlayer::RotateY);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ATwinStickShooterPlayer::FireButtonDown);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ATwinStickShooterPlayer::FireButtonUp);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ATwinStickShooterPlayer::Reload);
	PlayerInputComponent->BindAction("TSMelee", IE_Pressed, this, &ATwinStickShooterPlayer::MeleeAttack);
	PlayerInputComponent->BindAction("TSGrenade", IE_Pressed, this, &ATwinStickShooterPlayer::StartGrenadeThrow);
	PlayerInputComponent->BindAction("TSDash", IE_Pressed, this, &ATwinStickShooterPlayer::Dash);
	PlayerInputComponent->BindAction("TSInteract", IE_Pressed, this, &ATwinStickShooterPlayer::Interact);
}

void ATwinStickShooterPlayer::MoveForward(float Vertical)
{
	FVector Direction = MainCamera->GetForwardVector();

	if (Direction.Size() > 0.1)
	{
		//Multiplied by 2 because of the camera placement, will have to change if the camera is at a different angle
		AddMovementInput(Direction, Vertical * 2);
	}
}

void ATwinStickShooterPlayer::MoveRight(float Horizontal)
{
	FVector Direction = MainCamera->GetRightVector();

	if (Direction.Size() > 0.1)
	{
		AddMovementInput(Direction, Horizontal);
	}
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
	Health += HealingAmount;

	if (Health >= 1)
	{
		Health = 1;
	}

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Health: %f"), Health));
}

void ATwinStickShooterPlayer::ReceiveObjective(AObjective* Objective)
{
	//CurrentObjective = Objective;
	//Save(); Do a save timer instead
	CurrentObjective->Description = Objective->Description;
	CurrentObjective->Requirement = Objective->Requirement;
	CurrentObjective->Progress = Objective->Progress;
	CurrentObjective->bComplete = Objective->bComplete;
	CurrentObjective->CompleteText = Objective->CompleteText;
}

void ATwinStickShooterPlayer::Fire()
{
	if (CurrentWeapon)
	{
		if (CurrentWeapon->CanTheWeaponFire())
		{
			if (FiringAnimation)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(FiringAnimation, FiringAnimation->SequenceLength / CurrentWeapon->FireRate);
			}

			UAISense_Hearing::ReportNoiseEvent(this, GetActorLocation(), 1, this, 1500, FName("Sound"));
		}

		CurrentWeapon->Fire(WeaponMuzzle);
	}
}

void ATwinStickShooterPlayer::Reload()
{
	if (CurrentWeapon && bCanThrowGrenade)
	{
		if (CurrentWeapon->CanTheWeaponReload())
		{
			if (ReloadAnimation)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(ReloadAnimation, ReloadAnimation->SequenceLength / CurrentWeapon->ReloadSpeed);
				DisableLaserSight(CurrentWeapon->ReloadSpeed);
			}
		}

		CurrentWeapon->Reload();
	}
}

void ATwinStickShooterPlayer::FireButtonDown()
{
	bIsFiring = true;
}

void ATwinStickShooterPlayer::FireButtonUp()
{
	bIsFiring = false;
}

void ATwinStickShooterPlayer::MeleeAttack()
{
	if (CanPerformActions())
	{
		if (MeleeAnimation)
		{
			GetMesh()->GetAnimInstance()->Montage_Play(MeleeAnimation);
		}

		DisableLaserSight(MeleeCooldown);

		/*if (LaserSight)
		{
			LaserSight->SetVisibility(false);
		}*/

		bCanMelee = false;
		GetWorldTimerManager().SetTimer(MeleeTimerHandle, this, &ATwinStickShooterPlayer::RestoreMelee, MeleeCooldown, false);

		//TArray<TEnumAsByte<EObjectTypeQuery>> Query;
		TArray<AActor*> Ignore;
		Ignore.Add(this);
		//TArray<AActor*> OutHits;

		UGameplayStatics::ApplyRadialDamage(GetWorld(), MeleeDamage, GetActorLocation(), MeleeRange, UDamageType_Melee::StaticClass(), Ignore, this, GetController(), true);

		//UKismetSystemLibrary::SphereOverlapActors(this, GetActorLocation(), MeleeRange, Query, AParentEnemy::StaticClass(), Ignore, OutHits);

		//for (auto Enemy : OutHits)
		//{
		//	//UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *Enemy->GetClass()->GetName());

		//	if (Cast<AParentEnemy>(Enemy))
		//	{
		//		Cast<AParentEnemy>(Enemy)->GetHit(MeleeDamage);
		//		Cast<AParentEnemy>(Enemy)->GetStunned();
		//	}
		//}


	}
}

void ATwinStickShooterPlayer::RestoreMelee()
{
	GetWorldTimerManager().ClearTimer(MeleeTimerHandle);
	bCanMelee = true;

	/*if (LaserSight)
	{
		LaserSight->SetVisibility(true);
	}*/
}

void ATwinStickShooterPlayer::DisableLaserSight(float Duration)
{
	if (LaserSight)
	{
		LaserSight->SetVisibility(false);
	}

	GetWorldTimerManager().SetTimer(LaserSightTimerHandle, this, &ATwinStickShooterPlayer::EnableLaserSight, Duration, false);
}

void ATwinStickShooterPlayer::EnableLaserSight()
{
	if (LaserSight)
	{
		LaserSight->SetVisibility(true);
	}

	GetWorldTimerManager().ClearTimer(LaserSightTimerHandle);
}

//void ATwinStickShooterPlayer::SwapWeapons()
//{
//
//}

void ATwinStickShooterPlayer::StartGrenadeThrow()
{
	if (bCanThrowGrenade && !bGrenadeOnCooldown)
	{
		bCanThrowGrenade = false;
		bGrenadeOnCooldown = true;

		if (GrenadeThrowAnimation)
		{
			GrenadeThrowTime = GrenadeThrowAnimation->SequenceLength / GrenadeThrowAnimation->RateScale;
			GetWorldTimerManager().SetTimer(ThrowAnimationTimerHandle, this, &ATwinStickShooterPlayer::EndGrenadeThrow, GrenadeThrowTime, false);
			GetWorldTimerManager().SetTimer(GrenadeThrowTimerHandle, this, &ATwinStickShooterPlayer::ThrowGrenade, 0.7 * GrenadeThrowTime, false);
			GetMesh()->GetAnimInstance()->Montage_Play(GrenadeThrowAnimation);
			DisableLaserSight(GrenadeThrowTime);
		}

		else
		{
			GetWorldTimerManager().SetTimer(ThrowAnimationTimerHandle, this, &ATwinStickShooterPlayer::EndGrenadeThrow, GrenadeThrowTime, false);
		}
	}
}

void ATwinStickShooterPlayer::EndGrenadeThrow()
{
	GetWorldTimerManager().ClearTimer(ThrowAnimationTimerHandle);
	bCanThrowGrenade = true;
}

void ATwinStickShooterPlayer::ThrowGrenade()
{
	GetWorldTimerManager().SetTimer(GrenadeCooldownTimerHandle, this, &ATwinStickShooterPlayer::RestoreGrenade, GrenadeCooldown, false);
	GetWorldTimerManager().ClearTimer(GrenadeThrowTimerHandle);

	if (Grenade)
	{
		FActorSpawnParameters SpawnParams;
		GetWorld()->SpawnActor<AGrenade>(Grenade, GetActorTransform());
	}
}

void ATwinStickShooterPlayer::RestoreGrenade()
{
	GetWorldTimerManager().ClearTimer(GrenadeCooldownTimerHandle);
	bGrenadeOnCooldown = false;
}

void ATwinStickShooterPlayer::Dash()
{
	if (bCanDash && !bIsFiring)
	{
		bCanDash = false;
		//bIsFiring = false;

		DisableLaserSight(DashImmunityDuration);

		GetWorldTimerManager().SetTimer(DashTimerHandle, this, &ATwinStickShooterPlayer::RestoreDash, DashCooldown, false);
		GetWorldTimerManager().SetTimer(DashImmunityTimerHandle, this, &ATwinStickShooterPlayer::DashImmunityEnded, DashImmunityDuration, false);
		GetWorldTimerManager().SetTimer(DashRecoveryTimerHandle, this, &ATwinStickShooterPlayer::RecoverFromDash, DashRecoveryTime, false);

		DisableInput(UGameplayStatics::GetPlayerController(this, 0));

		FVector VerticaldDirection = GetInputAxisValue("TSForward") * DashForce * FVector(1, 0, 0);
		FVector HorizontalDirection = GetInputAxisValue("TSRight") * DashForce * FVector(0, 1, 0);

		FVector DashVelocity = VerticaldDirection + HorizontalDirection;

		LaunchCharacter(DashVelocity, true, true);

		bDamageImmune = true;
	}
}

void ATwinStickShooterPlayer::RestoreDash()
{
	GetWorldTimerManager().ClearTimer(DashTimerHandle);
	bCanDash = true;
}

void ATwinStickShooterPlayer::DashImmunityEnded()
{
	GetWorldTimerManager().ClearTimer(DashImmunityTimerHandle);
	bDamageImmune = false;
}

void ATwinStickShooterPlayer::RecoverFromDash()
{
	GetWorldTimerManager().ClearTimer(DashRecoveryTimerHandle);
	EnableInput(UGameplayStatics::GetPlayerController(this, 0));
}


bool ATwinStickShooterPlayer::CanPerformActions()
{
	bool bCanPerformActions = bCanMelee;
	if (CurrentWeapon)
	{
		bCanPerformActions = bCanPerformActions && !CurrentWeapon->bCurrentlyReloading;
	}

	if (Grenade)
	{
		bCanPerformActions = bCanPerformActions && bCanThrowGrenade;
	}

	return bCanPerformActions;
}

void ATwinStickShooterPlayer::Interact()
{
	////single line ray trace
	//FHitResult OutHit;
	//FVector Start = GetActorLocation();
	//FVector ForwardVector = GetActorForwardVector();

	//FVector End = ForwardVector * InteractRange + Start;
	//FCollisionQueryParams CollisionParams;

	//GetWorld()->LineTraceSingleByChannel(OUT OutHit, Start, End, ECollisionChannel(ECC_Visibility), CollisionParams);

	//if (Cast<AMinibossLevelPillar>(OutHit.GetActor()))
	//{
	//	Cast<AMinibossLevelPillar>(OutHit.GetActor())->PlantExplosive();
	//}

	/*if (LookForInteractablePillar())
	{
		LookForInteractablePillar()->PlantExplosive();
	}*/

	if (LookForInteractableActor())
	{
		LookForInteractableActor()->Interact();
		//LookForInteractablePillar()->PlantExplosive();
	}
}

//AMinibossLevelPillar* ATwinStickShooterPlayer::LookForInteractablePillar()
//{
//	FHitResult OutHit;
//	FVector Start = GetActorLocation();
//	FVector ForwardVector = GetActorForwardVector();
//
//	FVector End = ForwardVector * InteractRange + Start;
//	FCollisionQueryParams CollisionParams;
//
//	GetWorld()->LineTraceSingleByChannel(OUT OutHit, Start, End, ECollisionChannel(ECC_Visibility), CollisionParams);
//
//	return Cast<AMinibossLevelPillar>(OutHit.GetActor());
//}

AInteractableActor* ATwinStickShooterPlayer::LookForInteractableActor()
{
	FHitResult OutHit;
	FVector Start = GetActorLocation();
	FVector ForwardVector = GetActorForwardVector();

	FVector End = ForwardVector * InteractRange + Start;
	FCollisionQueryParams CollisionParams;

	GetWorld()->LineTraceSingleByChannel(OUT OutHit, Start, End, ECollisionChannel(ECC_Visibility), CollisionParams);

	return Cast<AInteractableActor>(OutHit.GetActor());
}

void ATwinStickShooterPlayer::Save()
{
	//UE_LOG(LogTemp, Warning, TEXT("Saving"));

	UJSaveGame* SaveGameInst = Cast<UJSaveGame>(UGameplayStatics::CreateSaveGameObject(UJSaveGame::StaticClass()));

	SaveGameInst->PlayerStats.Hp = Health * 100;
	//SaveGameInst->PlayerStats.Collectibles = Collectibles;
	SaveGameInst->PlayerStats.PlayerLocation = /*GetActorLocation();*/FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 50.f);
	SaveGameInst->PlayerStats.PlayerRotation = GetActorRotation();
	SaveGameInst->PlayerStats.LoadCheckpoint = true;
	SaveActors();
	UGameplayStatics::SaveGameToSlot(SaveGameInst, SaveGameInst->NameOfPlayer, SaveGameInst->IndexUser);
}

void ATwinStickShooterPlayer::Load()
{
	UJSaveGame* LoadGameInst = Cast<UJSaveGame>(UGameplayStatics::CreateSaveGameObject(UJSaveGame::StaticClass()));
	LoadGameInst = Cast<UJSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInst->NameOfPlayer, LoadGameInst->IndexUser));

	Health = LoadGameInst->PlayerStats.Hp / 100;
	SetActorLocation(LoadGameInst->PlayerStats.PlayerLocation);
	SetActorRotation(LoadGameInst->PlayerStats.PlayerRotation);
	//Collectibles = LoadGameInst->PlayerStats.Collectibles;
	//bShouldLoadCheckpoint = LoadGameInst->PlayerStats.LoadCheckpoint;
}

void ATwinStickShooterPlayer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (Health > 0)
	{
		UJSaveGame* SaveGameInst = Cast<UJSaveGame>(UGameplayStatics::CreateSaveGameObject(UJSaveGame::StaticClass()));
		SaveGameInst->PlayerStats.LoadCheckpoint = false;
		//SaveGameInst->PlayerStats.Collectibles = 0;
		UGameplayStatics::SaveGameToSlot(SaveGameInst, SaveGameInst->NameOfPlayer, SaveGameInst->IndexUser);
	}
}

void ATwinStickShooterPlayer::PickupCollectible()
{
	NumberOfCollectibles++;
}

void ATwinStickShooterPlayer::SaveActors()
{
	FOutputDeviceNull ar;
	this->CallFunctionByNameWithArguments(TEXT("SaveDestroyedActors"), ar, NULL, true);
}