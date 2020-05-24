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

}
