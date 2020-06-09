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
#include "Engine.h"
#include "PatrolPoint.h"
#include "Components/SphereComponent.h"
#include "Animation/AnimInstance.h"
#include "Sound/SoundCue.h"
#include "Kismet/KismetSystemLibrary.h"



// Sets default values
AJFollowEnemy::AJFollowEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("VisionBox"));
	VisionBox->SetupAttachment(GetRootComponent());

	FollowSphere = CreateDefaultSubobject<USphereComponent>(TEXT("FollowSphere"));
	FollowSphere->SetupAttachment(GetRootComponent());
	FollowSphere->InitSphereRadius(400.f);
	
	AttackSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AttackSphere"));
	AttackSphere->SetupAttachment(GetRootComponent());
	AttackSphere->InitSphereRadius(200.f);

	BoxCollFight = CreateDefaultSubobject<UBoxComponent>(TEXT("FightCollision"));
	BoxCollFight->SetBoxExtent(FVector(6.f, 6.f, 6.f));
	//BoxCollFight->SetBoundsScale(0.16f);
	
	// Socket fix
	BoxCollFight->SetupAttachment(GetMesh(), FName("RFArmSocket"));
	
	EFEnemyMoveStatus = EFEnemyMoveStat::FEMS_Idle;

	IsOverlapAttackSphere = false;

	Hp = 90.f;
	MaxHp = 100.f;
	Damage = 20.f;

	Delay = 4.f;

	IsWithGoal = false;

	IsFighting = false;

}



// Called when the game starts or when spawned
void AJFollowEnemy::BeginPlay()
{
	Super::BeginPlay();

	AIController = Cast<AAIController>(GetController());
	
	/*FollowSphere->OnComponentBeginOverlap.AddDynamic(this, &AJFollowEnemy::FollowSphereOnOverlapBegin);
	FollowSphere->OnComponentEndOverlap.AddDynamic(this, &AJFollowEnemy::FollowSphereOnOverlapEnd);*/

	VisionBox->OnComponentBeginOverlap.AddDynamic(this, &AJFollowEnemy::VisionBoxOnOverlapBegin);
	VisionBox->OnComponentEndOverlap.AddDynamic(this, &AJFollowEnemy::VisionBoxOnOverlapEnd);



	AttackSphere->OnComponentBeginOverlap.AddDynamic(this, &AJFollowEnemy::AttackSphereOnOverlapBegin);
	AttackSphere->OnComponentEndOverlap.AddDynamic(this, &AJFollowEnemy::AttackSphereOnOverlapEnd);

	BoxCollFight->OnComponentBeginOverlap.AddDynamic(this, &AJFollowEnemy::FightOnOverlapBegin);
	BoxCollFight->OnComponentEndOverlap.AddDynamic(this, &AJFollowEnemy::FightOnOverlapEnd);

	//Fix: Camera zooming when colliding with player
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

	BoxCollFight->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxCollFight->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	BoxCollFight->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxCollFight->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	

}

// Called every frame
void AJFollowEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	BasicPatrol(NextPatrolPoint);
}

// Called to bind functionality to input
void AJFollowEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AJFollowEnemy::VisionBoxOnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && IsLiving())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("OVERLAP BEGIN"));
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		if (Player)
		{
			MoveToPlayer(Player);
			
		}
	}
}





void AJFollowEnemy::VisionBoxOnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		{
			if (Player)
			{
				LastSeenPos = Player->GetActorLocation();

				if (AIController)
				{
					AIController->MoveToLocation(LastSeenPos);
					/*AIController->StopMovement();
					SetFEnemyMovStatus(EFEnemyMoveStat::FEMS_Idle);*/
				}

				DrawDebugSphere(GetWorld(), LastSeenPos, 50, 26, FColor(52, 220, 239), true, -1, 0, 2);

				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("OVERLAP END"));
				IsWithGoal = false;
				if (Player->FightGoal == this)
				{
					Player->SetFightGoal(nullptr);
				}
				Player->IsWithFightGoal;
				Player->FightGoalUpdate();
				
				
				
				
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
				IsOverlapAttackSphere = true;
				IsWithGoal = true;
				Player->SetFightGoal(this);
				AttackTarget = Player;
				
				Player->FightGoalUpdate();

				
				float FightLapsus = FMath::RandRange(0.5f, 1.5f);
				GetWorldTimerManager().SetTimer(FightTempo, this, &AJFollowEnemy::Fight, FightLapsus);
				
				
				
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
				IsFighting = false;
				MoveToPlayer(Player);
				IsOverlapAttackSphere = false;
					
				IsWithGoal = false;


					if (Player->FightGoal == this)
					{
						Player->IsWithFightGoal = false;
						Player->SetFightGoal(nullptr);
						Player->FightGoalUpdate();

					}
					GetWorldTimerManager().ClearTimer(FightTempo);
					
					
			}
		}
	}
}

void AJFollowEnemy::MoveToPlayer(AJBasePlayer* Player)
{
	if (!IsFighting)
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
		//Hp -= DamageAmount;
		Hp = 0.f;
		Death(DamageCauser);
	}
	else
	{
		Hp -= DamageAmount;
	}
	return DamageAmount;
}


void AJFollowEnemy::Fight()
{
	if (IsLiving() && IsWithGoal)
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
		FightFinished();
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

		float FightLapsus = FMath::RandRange(1.0f, 2.0f);
		GetWorldTimerManager().SetTimer(FightTempo, this, &AJFollowEnemy::Fight, FightLapsus);
		
	}
	
	
	
}

void AJFollowEnemy::BasicPatrol(APatrolPoint* Point)
{
	if (Point)
	{

		APatrolPoint* PatrolPoint = Cast<APatrolPoint>(Point);
		if (PatrolPoint)
		{
			FVector NewPos = PatrolPoint->GetActorLocation();
			if (AIController)
			{
				AIController->MoveToLocation(NewPos);
			}
		}
	}
}

void AJFollowEnemy::Death(AActor* DamageMaker)
{
	UAnimInstance* AnimationInst = GetMesh()->GetAnimInstance();
	if (AnimationInst)
	{
		AnimationInst->Montage_Play(FightMontage, 1.0f);
		AnimationInst->Montage_JumpToSection(FName("Death"), FightMontage);
	}
	SetFEnemyMovStatus(EFEnemyMoveStat::FEMS_Death);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	FollowSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxCollFight->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AttackSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	IsFighting = false;

	AJBasePlayer* Player = Cast<AJBasePlayer>(DamageMaker);
	if (Player)
	{
		Player->FightGoalUpdate();
	}

}

void AJFollowEnemy::EnemeyGhost()
{
	Destroy();
}