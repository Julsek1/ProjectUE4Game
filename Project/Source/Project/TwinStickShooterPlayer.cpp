// Fill out your copyright notice in the Description page of Project Settings.


#include "TwinStickShooterPlayer.h"

#include "Animation/AnimInstance.h"
#include "AssaultRifle.h"
#include "CustomGameInstance.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ParentEnemy.h"
#include "Shotgun.h"


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
}

// Called when the game starts or when spawned
void ATwinStickShooterPlayer::BeginPlay()
{
	Super::BeginPlay();

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

	//UE_LOG(LogTemp, Warning, TEXT("Max walk speed: %f"), GetCharacterMovement()->GetMaxSpeed());

	if (bIsFiring && bCanMelee)
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
			UE_LOG(LogTemp, Warning, TEXT("Self: %s"), *WeaponMuzzle->GetForwardVector().ToString());
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
	Health += HealingAmount;

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
		}

		CurrentWeapon->Fire(WeaponMuzzle);
	}
}

void ATwinStickShooterPlayer::Reload()
{
	if (CurrentWeapon)
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
	if (bCanMelee && CurrentWeapon && !CurrentWeapon->bCurrentlyReloading)
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

		//UKismetSystemLibrary::SphereTraceMulti(this, )

		TArray<TEnumAsByte<EObjectTypeQuery>> Query;
		TArray<AActor*> Ignore;
		Ignore.Add(this);
		TArray<AActor*> OutHits;

		UKismetSystemLibrary::SphereOverlapActors(this, GetActorLocation(), MeleeRange, Query, AActor::StaticClass(), Ignore, OutHits);

		for (auto Enemy : OutHits)
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *Enemy->GetClass()->GetName());

			if (Cast<AParentEnemy>(Enemy))
			{
				Cast<AParentEnemy>(Enemy)->Health -= MeleeDamage;
			}
		}
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

void ATwinStickShooterPlayer::SwapWeapons()
{

}
