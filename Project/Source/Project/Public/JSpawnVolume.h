// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JSpawnVolume.generated.h"

UCLASS()
class PROJECT_API AJSpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJSpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn")
	class UBoxComponent* SpawnBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
	TSubclassOf <class APRJPawn> PawnToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Spawn")
	FVector GetSpawnPoint();

	//spawn any class type
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawn")
		void SpawnGamePawn(UClass* ToBeSpawned, const FVector& Position);

};
