// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "InteractableSecret.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AInteractableSecret : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	AInteractableSecret();
	void Interact() override;
	int32 TimesInteractedWith = 0;
};
