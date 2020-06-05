// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable.h"
#include "Engine/World.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "JBasePlayer.h"

ACollectable::ACollectable()
{

	CollectCount = 1;

}

void ACollectable::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		if (Player)
		{
			Player->CollectUp(CollectCount);
			if (BasicPSComponent)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PSOverlap, GetActorLocation(), FRotator(0.f), true);

			}
			if (SoundFX)
			{
				UGameplayStatics::PlaySound2D(this, SoundFX);
			}
			Destroy();
		}
	}
}

void ACollectable::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("CollectibleOverlapEnd"));
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);


}
