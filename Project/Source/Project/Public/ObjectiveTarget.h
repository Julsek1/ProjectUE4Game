// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectiveTarget.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECT_API UObjectiveTarget : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UObjectiveTarget();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bShouldSaveProgress = false;

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
public:
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	bool bDestroyed = false;
};
