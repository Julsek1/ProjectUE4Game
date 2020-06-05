// Fill out your copyright notice in the Description page of Project Settings.


#include "JFollowEnemy.h"
#include "AIController.h"
#include "Components/BoxComponent.h"
#include "Project/Public/JBasePlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "TimerManager.h"
#include "Components/SphereComponent.h"
#include "Animation/AnimInstance.h"
#include "Sound/SoundCue.h"
#include "Kismet/KismetSystemLibrary.h"



// Sets default values
AJFollowEnemy::AJFollowEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FollowSphere = CreateDefaultSubobject<USphereComponent>(TEXT("FollowSphere"));
	FollowSphere->SetupAttachment(GetRootComponent());
	FollowSphere->InitSphereRadius(400.f);
	
	AttackSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AttackSphere"));
	AttackSphere->SetupAttachment(GetRootComponent());
	AttackSphere->InitSphereRadius(200.f);

	BoxCollFight = CreateDefaultSubobject<UBoxComponent>(TEXT("FightCollision"));
	BoxCollFight->SetBoxExtent(FVector(6.f, 6.f, 6.f));
	//BoxCollFight->SetBoundsScale(0.16f);
	
	EFEnemyMoveStatus = EFEnemyMoveStat::FEMS_Idle;

	IsOverlapAttackSphere = false;

	Hp = 90.f;
	MaxHp = 100.f;
	Damage = 20.f;

	Delay = 4.f;

}



// Called when the game starts or when spawned
void AJFollowEnemy::BeginPlay()
{
	Super::BeginPlay();

	AIController = Cast<AAIController>(GetController());
	
	FollowSphere->OnComponentBeginOverlap.AddDynamic(this, &AJFollowEnemy::FollowSphereOnOverlapBegin);
	FollowSphere->OnComponentEndOverlap.AddDynamic(this, &AJFollowEnemy::FollowSphereOnOverlapEnd);


	AttackSphere->OnComponentBeginOverlap.AddDynamic(this, &AJFollowEnemy::AttackSphereOnOverlapBegin);
	AttackSphere->OnComponentEndOverlap.AddDynamic(this, &AJFollowEnemy::AttackSphereOnOverlapEnd);

	BoxCollFight->OnComponentBeginOverlap.AddDynamic(this, &AJFollowEnemy::FightOnOverlapBegin);
	BoxCollFight->OnComponentEndOverlap.AddDynamic(this, &AJFollowEnemy::FightOnOverlapEnd);

	//Arm socket fix

	//BoxCollFight->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("RFArmSocket"));

	BoxCollFight->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("RFArmSocket"));

	BoxCollFight->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxCollFight->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	BoxCollFight->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxCollFight->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	//SetFEnemyMovStatus(EFEnemyMoveStat::FEMS_Idle);

}

// Called every frame
void AJFollowEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJFollowEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AJFollowEnemy::FollowSphereOnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && IsLiving())
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		if (Player)
		{
			MoveToPlayer(Player);
		}
	}
}

void AJFollowEnemy::FollowSphereOnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		{
			if (Player)
			{
				SetFEnemyMovStatus(EFEnemyMoveStat::FEMS_Idle);
				if (AIController)
				{
					AIController->StopMovement();
				}
			}
		}
	}

}

void AJFollowEnemy::AttackSphereOnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && IsLiving())
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		{
			if (Player)
			{
				Player->SetFightGoal(this);
				AttackTarget = Player;
				IsOverlapAttackSphere = true;
				Fight();
			}
		}
	}
}

void AJFollowEnemy::AttackSphereOnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		{
			if (Player)
			{
				if (Player->FightGoal == this)
				{
					Player->SetFightGoal(nullptr);
				}
				IsOverlapAttackSphere = false;
				if (EFEnemyMoveStatus != EFEnemyMoveStat::FEMS_Attack)
				{
					MoveToPlayer(Player);
					AttackTarget = nullptr;
				}
				GetWorldTimerManager().ClearTimer(FightTempo);
			}
		}
	}
}

void AJFollowEnemy::MoveToPlayer(AJBasePlayer* Player)
{
	SetFEnemyMovStatus(EFEnemyMoveStat::FEMS_MoveToPlayer);

	if (AIController)
	{
		//struct MoveRequest
		FAIMoveRequest MoveRequest;
		MoveRequest.SetGoalActor(Player);
		MoveRequest.SetAcceptanceRadius(15.f);

		//struct NavPath
		FNavPathSharedPtr NavigationPath;
		AIController->MoveTo(MoveRequest, &NavigationPath);
		

	}
}

void AJFollowEnemy::FightOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		if (Player)
		{
			if (Player->TakeHitPS)
			{
				const USkeletalMeshSocket* FingerSocket = GetMesh()->GetSocketByName("FingerSocket");
				if (FingerSocket)
				{
					FVector LocOfSocket = FingerSocket->GetSocketLocation(GetMesh());
					UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Player->TakeHitPS, LocOfSocket, FRotator(0.f), false);

				}
			}
			if (Player->DamageSound)
			{
				UGameplayStatics::PlaySound2D(this, Player->DamageSound);
			}
			if (DamageTypeClass)
			{
				UGameplayStatics::ApplyDamage(Player, Damage, AIController, this, DamageTypeClass);
			}
		}
	}
}

void AJFollowEnemy::FightOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AJFollowEnemy::CollisionActive()
{
	BoxCollFight->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AJFollowEnemy::CollisionInactive()
{
	BoxCollFight->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

bool AJFollowEnemy::IsLiving()
{
	return GetFEnemyMovStatus() != EFEnemyMoveStat::FEMS_Death;
}

float AJFollowEnemy::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	
	if (Hp - DamageAmount <= 0.f)
	{
		Hp -= DamageAmount;
		Death();
	}
	else
	{
		Hp -= DamageAmount;
	}
	return DamageAmount;
}


void AJFollowEnemy::Fight()
{
	if (IsLiving())
	{
		if (AIController)
		{
			AIController->StopMovement();
			SetFEnemyMovStatus(EFEnemyMoveStat::FEMS_Attack);
		}
		if (!IsFighting)
		{
			IsFighting = true;
			UAnimInstance* AnimationInst = GetMesh()->GetAnimInstance();
			if (AnimationInst)
			{
				AnimationInst->Montage_Play(FightMontage, 1.5f);
				AnimationInst->Montage_JumpToSection(FName("Attack"), FightMontage);
			}
			if (PunchSound)
			{
				UGameplayStatics::PlaySound2D(this, PunchSound);
			}
		}
	}
	
}

void AJFollowEnemy::EnemyFinished()
{
	GetMesh()->bPauseAnims = true;
	GetMesh()->bNoSkeletonUpdate = true;
	GetWorldTimerManager().SetTimer(DyingTempo, this, &AJFollowEnemy::EnemeyGhost, Delay);
}

void AJFollowEnemy::FightFinished()
{
	IsFighting = false;
	if (IsOverlapAttackSphere)
	{
		float FightLapsus = FMath::RandRange(0.5f, 2.5f);
		GetWorldTimerManager().SetTimer(FightTempo, this, &AJFollowEnemy::Fight, FightLapsus);
		
	}
}

void AJFollowEnemy::Death()
{
	UAnimInstance* AnimationInst = GetMesh()->GetAnimInstance();
	if (AnimationInst)
	{
		AnimationInst->Montage_Play(FightMontage, 1.5f);
		AnimationInst->Montage_JumpToSection(FName("Death"), FightMontage);
	}
	SetFEnemyMovStatus(EFEnemyMoveStat::FEMS_Death);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	FollowSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxCollFight->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AttackSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	

}

void AJFollowEnemy::EnemeyGhost()
{
	Destroy();
}