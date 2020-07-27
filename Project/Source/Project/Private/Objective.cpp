// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "../TwinStickShooterPlayer.h"

void AObjective::UpdateProgress()
{
	Progress++;
	
	//save
	auto Player = Cast<ATwinStickShooterPlayer>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	if (Player)
	{
		Player->Save();
	}

	if (Progress >= Requirement)
	{
		bComplete = true;
		GetWorldTimerManager().SetTimer(CompleteTimerHandle, this, &AObjective::DisplayCompleteText, 3, false);
	}
}

void AObjective::DisplayCompleteText()
{
	GetWorldTimerManager().ClearTimer(CompleteTimerHandle);

	Description = CompleteText;
	bComplete = false;
	Progress = 0;
	Requirement = 0;
}