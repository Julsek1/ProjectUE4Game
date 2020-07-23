// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TSDamageableActorWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UTSDamageableActorWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
		class ADamageableActor* Actor;
};
