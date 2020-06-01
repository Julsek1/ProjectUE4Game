// Fill out your copyright notice in the Description page of Project Settings.


#include "JFollowEnemy.h"
#include "AIController.h"
#include "Components/BoxComponent.h"
#include "Project/Public/JBasePlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMeshSocket.h"
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
	AttackSphere->InitSphereRadius(150.f);

	BoxCollFight = CreateDefaultSubobject<UBoxComponent>(TEXT("FightCollision"));
	BoxCollFight->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("RFArmSocket"));
	
	

	

	IsOverlapAttackSphere = false;

	Hp = 80.f;
	MaxHp = 100.f;
	Damage = 15.f;
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

	BoxCollFight->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxCollFight->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	BoxCollFight->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxCollFight->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	BoxCollFight->OnComponentBeginOverlap.AddDynamic(this, &AJFollowEnemy::FightOnOverlapBegin);
	BoxCollFight->OnComponentEndOverlap.AddDynamic(this, &AJFollowEnemy::FightOnOverlapEnd);

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
	if (OtherActor)
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
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		{
			if (Player)
			{
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
				IsOverlapAttackSphere = false;
				if (EFEnemyMoveStatus != EFEnemyMoveStat::FEMS_Attack)
				{
					MoveToPlayer(Player);
					AttackTarget = nullptr;
				}
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


		//array of pathpoints
		auto PathPoints = NavigationPath->GetPathPoints();
		for (auto point : PathPoints)
		{
			FVector Location = point.Location;

			UKismetSystemLibrary::DrawDebugSphere(this, Location, 25.f, 8, FLinearColor::Blue, 10.f, 2.f);
		}

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

void AJFollowEnemy::Fight()
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

void AJFollowEnemy::FightFinished()
{
	IsFighting = false;
	if (IsOverlapAttackSphere)
	{
		Fight();
	}
}
