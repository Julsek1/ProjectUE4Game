// Fill out your copyright notice in the Description page of Project Settings.


#include "Mine.h"
#include "Engine/World.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "JBasePlayer.h"


AMine::AMine()
{
	Damage = 20.f;
}

void AMine::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		if (Player)
		{
			if (BasicPSComponent)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PSOverlap, GetActorLocation(), FRotator(0.f), true);

			}
			if (SoundFX)
			{
				UGameplayStatics::PlaySound2D(this, SoundFX);
			}
			Player->DamageHp(Damage);
			Destroy();
		}
	}
}

void AMine::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	
}
