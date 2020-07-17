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
	TSubclassOf <class AActor> ActorToSpawn1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
	TSubclassOf <class AActor> ActorToSpawn2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
	TSubclassOf <class AActor> ActorToSpawn3;

	TArray<TSubclassOf<AActor>> ArrayToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintPure, Category = "Spawn")
	TSubclassOf <AActor> GetSpawnActor();

	UFUNCTION(BlueprintPure, Category = "Spawn")
	FVector GetSpawnLocation();

	//spawn any class type
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawn")
	void SpawnGameActor(UClass* ToBeSpawned, const FVector& Position);

};
