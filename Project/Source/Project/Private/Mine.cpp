// Fill out your copyright notice in the Description page of Project Settings.


#include "Mine.h"
#include "Engine/World.h"
#include "Sound/SoundCue.h"
#include "JFollowEnemy.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "JBasePlayer.h"


AMine::AMine()
{
	Damage = 20.f;
	/*DefuseSphere = CreateDefaultSubobject<USphereComponent>(TEXT("DefuseSphere"));
	
	DefuseSphere->SetupAttachment(Mesh);
	DefuseSphere->InitSphereRadius(12.f);*/

	ColliderSphere->SetupAttachment(Mesh);
	ColliderSphere->InitSphereRadius(18.f);

	WasDefused = false;

	IsATrap = false;

}




void AMine::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	if (OtherActor)
	{
		AJBasePlayer* Player = Cast<AJBasePlayer>(OtherActor);
		AJFollowEnemy* Mutant = Cast<AJFollowEnemy>(OtherActor);

		if (Player || Mutant)
		{
			if ((Player->IsCrawling == false) || IsATrap)
			{
				if (BasicPSComponent)
				{
					UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PSOverlap, GetActorLocation(), FRotator(0.f), true);

				}
				if (SoundFX)
				{
					UGameplayStatics::PlaySound2D(this, SoundFX);
				}

				UGameplayStatics::ApplyDamage(OtherActor, Damage, nullptr, this, DamageTypeClass);
				Destroy();

				if (WasDefused)
				{
					Destroy();
				}
			}
		}
	}
}

void AMine::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	
}
