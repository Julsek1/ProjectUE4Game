// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelLoader.h"
#include "CustomGameInstance.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "TwinStickShooterPlayer.h"

// Sets default values for this component's properties
ULevelLoader::ULevelLoader()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULevelLoader::BeginPlay()
{
	Super::BeginPlay();

	// ...

	//UE_LOG(LogTemp, Warning, TEXT("%s has a LevelLoader"), *GetOwner()->GetName());
	
	
}


// Called every frame
void ULevelLoader::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	ACharacter* Player = GetWorld()->GetFirstPlayerController()->GetCharacter();

	if (Cast<ATwinStickShooterPlayer>(Player) != nullptr)
	{
		GetWorld()->GetGameInstance<UCustomGameInstance>()->PlayerHealth = Cast<ATwinStickShooterPlayer>(Player)->Health;
	}

	if (LevelName != "" && Trigger && !LoadingLevel && Trigger->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetPawn()))//GetWorld()->GetFirstPlayerController()->GetCharacter(); Can be changed to player later, will not work in hub world as is
	{
		UE_LOG(LogTemp, Warning, TEXT("Loading the next level"));
		LoadingLevel = true;
		//load level
		UGameplayStatics::OpenLevel(this, LevelName);

		//How do I set the gamemode

		//? Game = / Game / Player / Blueprints / ThirdPersonGameMode.ThirdPersonGameMode_C
		//C:/Users/philf/Desktop/School/Internship Project/ProjectUE4Game/Project/Content/Phil/Blueprints/BP_TwinStickShooter.uasset
	}
}

