// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableTerminal.h"

AInteractableTerminal::AInteractableTerminal()
{
	InteractMessage = "Interact to hack the terminal";
	/*WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	WidgetComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);*/
}

void AInteractableTerminal::Interact()
{
	Super::Interact();
	GetWorldTimerManager().SetTimer(HackTimerHandle, this, &AInteractableTerminal::HackComplete, HackTime, false);
}

void AInteractableTerminal::HackComplete()
{
	GetWorldTimerManager().ClearTimer(HackTimerHandle);
	Destroy();
}