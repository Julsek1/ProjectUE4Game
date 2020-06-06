// Fill out your copyright notice in the Description page of Project Settings.


#include "JSpawnVolume.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Project/Public/PRJPawn.h"

// Sets default values
AJSpawnVolume::AJSpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));


}

// Called when the game starts or when spawned
void AJSpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	if (ActorToSpawn1 && ActorToSpawn2 && ActorToSpawn3)
	{
		ArrayToSpawn.Add(ActorToSpawn1);
		ArrayToSpawn.Add(ActorToSpawn2);
		ArrayToSpawn.Add(ActorToSpawn3);
	}
	
}

// Called every frame
void AJSpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TSubclassOf<AActor> AJSpawnVolume::GetSpawnActor()
{
	if (ArrayToSpawn.Num() > 0)
	{
		int32 Option = FMath::RandRange(0, ArrayToSpawn.Num() -1);

		return ArrayToSpawn[Option];
	}
	else
	{
		return nullptr;
	}
}

FVector AJSpawnVolume::GetSpawnLocation()
{
	FVector Extension = SpawnBox->GetScaledBoxExtent();
	FVector StartingPoint = SpawnBox->GetComponentLocation();

	FVector Point = UKismetMathLibrary::RandomPointInBoundingBox(StartingPoint, Extension);
	
	return Point;
}

void AJSpawnVolume::SpawnGameActor_Implementation(UClass* ToBeSpawned, const FVector& Position)
{
	if (ToBeSpawned)
	{
		UWorld* World = GetWorld();
		FActorSpawnParameters SpawnParameters;
		if (World)
		{
			World->SpawnActor<AActor>(ToBeSpawned, Position, FRotator(0.0f), SpawnParameters);
		}
	}
}

