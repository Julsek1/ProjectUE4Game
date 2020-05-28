// Fill out your copyright notice in the Description page of Project Settings.


#include "ParentEnemy.h"
#include "Kismet/GameplayStatics.h"
#include "TSEnemyWidget.h"


// Sets default values
AParentEnemy::AParentEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	WidgetComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AParentEnemy::BeginPlay()
{
	Super::BeginPlay();
	Cast<UTSEnemyWidget>(WidgetComponent->GetUserWidgetObject())->Enemy = this;
}

// Called every frame
void AParentEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Health <= 0)
	{
		Destroy();
	}

	/*auto camera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	WidgetComponent->SetWorldRotation(camera->GetCameraRotation());
	WidgetComponent->AddLocalRotation(FRotator(0, 180, 0));*/
}

// Called to bind functionality to input
void AParentEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

