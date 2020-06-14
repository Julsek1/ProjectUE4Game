// Fill out your copyright notice in the Description page of Project Settings.


#include "ParentEnemy.h"

#include "DamageType_Explosive.h"
#include "DamageType_Melee.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TSEnemyWidget.h"


// Sets default values
AParentEnemy::AParentEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	WidgetComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	EnemyName = "";
}

// Called when the game starts or when spawned
void AParentEnemy::BeginPlay()
{
	Super::BeginPlay();
	Cast<UTSEnemyWidget>(WidgetComponent->GetUserWidgetObject())->Enemy = this;
}

// Called every frame
void AParentEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Health <= 0)
	{
		if (!bIsDead)
		{
			GetWorldTimerManager().SetTimer(DeathDespawnTimerHandle, this, &AParentEnemy::Despawn, TimeToDespawn, false);
			bIsDead = true;
			GetMesh()->SetSimulatePhysics(true);
			GetMesh()->AddForceToAllBodiesBelow(DirectionOfLastHit * ForceOfLastHit, FName("Spine"), true, true);
			//GetCharacterMovement()->AddImpulse(FVector(100000.f, 100000.f, 100000.f));
			WidgetComponent->SetVisibility(false);
		}
		//Destroy();
	}

	/*auto camera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	WidgetComponent->SetWorldRotation(camera->GetCameraRotation());
	WidgetComponent->AddLocalRotation(FRotator(0, 180, 0));*/
}

void AParentEnemy::Despawn()
{
	GetWorldTimerManager().ClearTimer(DeathDespawnTimerHandle);

	Destroy();
}

// Called to bind functionality to input
void AParentEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AParentEnemy::GetStunned()
{
	if (!bStunnedRecently)
	{
		bStunnedRecently = true;
		GetWorldTimerManager().SetTimer(StunCooldownTimerHandle, this, &AParentEnemy::StunCooldownElapsed, StunCooldown, false);

		bIsStunned = true;
		GetWorldTimerManager().SetTimer(StunTimerHandle, this, &AParentEnemy::PurgeStun, StunDuration, false);
	}
}

void AParentEnemy::PurgeStun()
{
	bIsStunned = false;
	GetWorldTimerManager().ClearTimer(StunTimerHandle);
}

void AParentEnemy::StunCooldownElapsed()
{
	bStunnedRecently = false;
	GetWorldTimerManager().ClearTimer(StunCooldownTimerHandle);
}

void AParentEnemy::GetHit(float Damage, float Force, FVector Direction)
{
	Health -= (Damage - Damage * DamageResistance);
	ForceOfLastHit = Force;
	DirectionOfLastHit = Direction;
}

float AParentEnemy::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	if (Cast<UDamageType_Explosive>(DamageEvent.DamageTypeClass.GetDefaultObject()))
	{
		FVector Difference = GetActorLocation() - DamageCauser->GetActorLocation();
		FVector Direction;
		float Length;
		Difference.ToDirectionAndLength(Direction, Length);
		GetHit(DamageAmount, Cast<UDamageType_Explosive>(DamageEvent.DamageTypeClass.GetDefaultObject())->Force, Direction);
	}

	else if (Cast<UDamageType_Melee>(DamageEvent.DamageTypeClass.GetDefaultObject()))
	{
		GetHit(DamageAmount);
		GetStunned();
	}

	return 0;
}