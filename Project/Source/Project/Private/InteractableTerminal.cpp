// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableTerminal.h"

AInteractableTerminal::AInteractableTerminal()
{
	InteractMessage = "Interact to hack the terminal";
}

void AInteractableTerminal::Interact()
{
	Super::Interact();
}