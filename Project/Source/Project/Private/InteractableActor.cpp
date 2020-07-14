// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor.h"

// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	InteractMessage = "Testing this out. Hope it works.";
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
//void AInteractableActor::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}

// Called every frame
//void AInteractableActor::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void AInteractableActor::Interact()
{
	bHasBeenInteractedWith = true;
}