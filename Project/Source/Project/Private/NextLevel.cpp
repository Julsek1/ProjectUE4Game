// Fill out your copyright notice in the Description page of Project Settings.


#include "NextLevel.h"
#include "JBasePlayer.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ANextLevel::ANextLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	NextLevelBox = CreateDefaultSubobject<UBoxComponent>(("NextLevelBox"));
	RootComponent = NextLevelBox;

	Bb = CreateDefaultSubobject<UBillboardComponent>(("Billboard"));
	Bb->SetupAttachment(GetRootComponent());

	LevelName = "TestMap";

}

// Called when the game starts or when spawned
void ANextLevel::BeginPlay()
{
	Super::BeginPlay();

	NextLevelBox->OnComponentBeginOverlap.AddDynamic(this, &ANextLevel::OnOverlapBegin);
	
}

// Called every frame
void ANextLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANextLevel::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		if (Player)
		{
			Player->GoToNextLevel(LevelName);
		}
	}
}

