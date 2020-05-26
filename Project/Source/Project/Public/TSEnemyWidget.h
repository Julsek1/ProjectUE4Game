// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TSEnemyWidget.generated.h"

UCLASS()
class PROJECT_API UTSEnemyWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
		class AParentEnemy* Enemy;
};
