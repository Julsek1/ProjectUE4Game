// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveGiver.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "../TwinStickShooterPlayer.h"

// Sets default values
AObjectiveGiver::AObjectiveGiver()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	RootComponent = Collider;
}

//Called when the game starts or when spawned
void AObjectiveGiver::BeginPlay()
{
	Super::BeginPlay();
	if (bSeekPlayer)
	{
		SetActorLocation(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
	}


}

//Called every frame
//void AObjectiveGiver::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	
//}

//void AObjectiveGiver::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& hit)
//{
//	//UE_LOG(LogTemp, Warning, TEXT("Hit"));
//
//	if (Cast<ATwinStickShooterPlayer>(Other) != nullptr && Objective)
//	{
//		Cast<ATwinStickShooterPlayer>(Other)->ReceiveObjective(Objective);
//	}
//
//	Destroy();
//}

void AObjectiveGiver::NotifyActorBeginOverlap(AActor* Other)
{
	if (Cast<ATwinStickShooterPlayer>(Other) != nullptr && Objective)
	{
		Cast<ATwinStickShooterPlayer>(Other)->ReceiveObjective(Objective);

		DestroySelfAndLinked();
	}
}

void AObjectiveGiver::NotifyActorEndOverlap(AActor* Other)
{
	if (Cast<ATwinStickShooterPlayer>(Other) != nullptr && Objective)
	{
		Cast<ATwinStickShooterPlayer>(Other)->ReceiveObjective(Objective);

		DestroySelfAndLinked();
	}
}

void AObjectiveGiver::DestroySelfAndLinked()
{
	for (auto LinkedObjective : LinkedObjectives)
	{
		if (LinkedObjective)
		{
			LinkedObjective->Destroy();
		}
	}
	
	Destroy();
}