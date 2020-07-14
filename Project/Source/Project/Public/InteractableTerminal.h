// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "InteractableTerminal.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AInteractableTerminal : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	AInteractableTerminal();

	void Interact() override;
};
