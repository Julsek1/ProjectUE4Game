// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableTerminal.h"
#include "TSHackWidget.h"

AInteractableTerminal::AInteractableTerminal()
{
	InteractMessage = "Interact to hack the terminal";
	/*WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	WidgetComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);*/
}

// Called when the game starts or when spawned
void AInteractableTerminal::BeginPlay()
{
	Super::BeginPlay();
	//Cast<UTSHackWidget>(WidgetComponent->GetUserWidgetObject())->Terminal = this;
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