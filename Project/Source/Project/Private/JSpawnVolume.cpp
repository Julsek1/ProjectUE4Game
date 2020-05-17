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
	
}

// Called every frame
void AJSpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector AJSpawnVolume::GetSpawnPoint()
{
	FVector Extension = SpawnBox->GetScaledBoxExtent();
	FVector StartingPoint = SpawnBox->GetComponentLocation();

	FVector Point = UKismetMathLibrary::RandomPointInBoundingBox(StartingPoint, Extension);
	
	return Point;
}

//"_Implementation" to be implemented in both C++ and blueprints
void AJSpawnVolume::SpawnGamePawn_Implementation(UClass* ToBeSpawned, const FVector& Position)
{
	if (ToBeSpawned)
	{
		UWorld* World = GetWorld();
		FActorSpawnParameters SpawnParameters;
		if (World)
		{
		 APRJPawn* EnemySpawned = World->SpawnActor<APRJPawn>(ToBeSpawned, Position, FRotator(0.0f), SpawnParameters);
		}
	}
}