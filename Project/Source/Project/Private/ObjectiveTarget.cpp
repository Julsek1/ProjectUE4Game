// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveTarget.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "../TwinStickShooterPlayer.h"

// Sets default values for this component's properties
UObjectiveTarget::UObjectiveTarget()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;

	// ...
}


//// Called when the game starts
//void UObjectiveTarget::BeginPlay()
//{
//	Super::BeginPlay();
//
//	// ...
//	
//}

void UObjectiveTarget::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	if (GetWorld() && GetWorld()->IsGameWorld() && !bDestroyed)
	{
		bDestroyed = true;

		ATwinStickShooterPlayer* Player = Cast<ATwinStickShooterPlayer>(GetWorld()->GetFirstPlayerController()->GetCharacter());

		if (Player && Player->CurrentObjective)
		{
			Player->CurrentObjective->UpdateProgress();
			
			//Save progress
			if (bShouldSaveProgress)
			{
				Player->Save();
			}
		}
	}

}


//// Called every frame
//void UObjectiveTarget::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

