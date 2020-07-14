// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/WidgetComponent.h"
#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "TimerManager.h"
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

	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UWidgetComponent* WidgetComponent;*/

	void HackComplete();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float HackTime = 30.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FTimerHandle HackTimerHandle;
};
