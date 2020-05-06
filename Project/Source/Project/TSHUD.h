// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
//#include "TwinStickShooterPlayer.h"
#include "TSHUD.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UTSHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadonly)
		class ATwinStickShooterPlayer* Player;
};
