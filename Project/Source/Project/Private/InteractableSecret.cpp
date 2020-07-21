// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableSecret.h"

AInteractableSecret::AInteractableSecret()
{
	InteractMessage = "This is a secret.";
}

void AInteractableSecret::Interact()
{
	switch (++TimesInteractedWith)
	{
	case 1:
		InteractMessage = "Is it really?";
		break;
	case 2:
		InteractMessage = "It is.";
		break;
	case 3:
		InteractMessage = "I feel like you had a gap and were too lazy to fix it.";
		break;
	case 4:
		InteractMessage = "Would a lazy person make this secret?";
		break;
	case 5:
		InteractMessage = "Yup.";
		break;
	case 6:
		InteractMessage = "Rude. No more secret then.";
		break;
	case 7:
		bHasBeenInteractedWith = true;
	}
}

