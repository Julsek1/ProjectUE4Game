// Fill out your copyright notice in the Description page of Project Settings.


#include "ToggleableActor.h"

// Sets default values
AToggleableActor::AToggleableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = StaticMesh;
}

// Called when the game starts or when spawned
//void AToggleableActor::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}

// Called every frame
//void AToggleableActor::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void AToggleableActor::Toggle()
{
	if (StaticMesh->IsCollisionEnabled())
	{
		StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		StaticMesh->SetVisibility(false);
	}

	else
	{
		StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		StaticMesh->SetVisibility(true);
	}
}