// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"
#include "Blueprint/UserWidget.h"



void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (HUDFirstLayerItem)
	{
		HUDFirstLayer = CreateWidget<UUserWidget>(this, HUDFirstLayerItem);
	}
	
	//add to viewport (as in BP)
	HUDFirstLayer->AddToViewport();
	HUDFirstLayer->SetVisibility(ESlateVisibility::Visible);

	if (WidgetPause)
	{
		PMenu =CreateWidget<UUserWidget>(this, WidgetPause);
		if (PMenu)
		{
			PMenu->AddToViewport();
			PMenu->SetVisibility(ESlateVisibility::Hidden);
		}
	}

	

}

void ABasePlayerController::DisplayPMenu()
{
	if (PMenu)
	{

		PMenuVisible = true;
		PMenu->SetVisibility(ESlateVisibility::Visible);

	}
}

void ABasePlayerController::EliminatePMenu()
{
	if (PMenu)
	{

		PMenuVisible = false;
		PMenu->SetVisibility(ESlateVisibility::Hidden);

	}
}

void ABasePlayerController::CheckPMenu()
{
	if (PMenuVisible)
	{
		EliminatePMenu();
	}
	else
	{
		DisplayPMenu();
	}
}
