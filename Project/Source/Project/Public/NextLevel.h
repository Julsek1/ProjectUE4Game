// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NextLevel.generated.h"

UCLASS()
class PROJECT_API ANextLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANextLevel();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NextLevel")
	class UBoxComponent* NextLevelBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NextLevel")
	FName LevelName;

	class UBillboardComponent* Bb;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	

};
