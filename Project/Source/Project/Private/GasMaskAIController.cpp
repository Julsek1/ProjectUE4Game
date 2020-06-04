// Fill out your copyright notice in the Description page of Project Settings.


#include "GasMaskAIController.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Kismet/GameplayStatics.h"
#include "../TwinStickShooterPlayer.h"

AGasMaskAIController::AGasMaskAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent")));

	//setup sight config
	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	//setup perception component
	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AGasMaskAIController::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}

void AGasMaskAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetPerceptionComponent() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Using GasMaskAIC"));
	}
}

void AGasMaskAIController::OnPossess(APawn* PawnToPossess)
{
	Super::OnPossess(PawnToPossess);
}

void AGasMaskAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (DistanceToPlayer > AISightRadius)
	{
		bIsPlayerDetected = false;
	}

	if (bIsPlayerDetected)
	{
		AParentPlayer* Player = Cast<AParentPlayer>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		MoveToActor(Player);
	}

	else
	{
		//Patrol?
	}
}

FRotator AGasMaskAIController::GetControlRotation() const
{
	if (GetPawn() == nullptr)
	{
		return FRotator(0.f, 0.f, 0.f);
	}

	return FRotator(0.f, GetPawn()->GetActorRotation().Yaw, 0.f);
}

void AGasMaskAIController::OnPawnDetected(const TArray<AActor*>& DetectedPawns)//gets called when the player enters or exits the AI sight radius
{
	for (auto Actor : DetectedPawns)
	{
		DistanceToPlayer = GetPawn()->GetDistanceTo(Actor);
	}

	bIsPlayerDetected = true;
}


