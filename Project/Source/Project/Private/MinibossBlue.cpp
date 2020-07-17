// Fill out your copyright notice in the Description page of Project Settings.


#include "MinibossBlue.h"
#include "Animation/AnimInstance.h"

AMinibossBlue::AMinibossBlue()
{
	Color = FColor::Blue;

	LaserSight = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("LaserSight"));
	LaserSight->SetupAttachment(GetMesh());
}

void AMinibossBlue::Tick(float DeltaTime)
{
	if (LaserSight)
	{
		TArray<FHitResult> OutHits;
		FVector Start = LaserSight->GetComponentLocation();
		FCollisionQueryParams CollisionParams;
		float LaserSightDistance = Sniper->Range;

		FVector End = LaserSight->GetForwardVector() * LaserSightDistance + LaserSight->GetComponentLocation();
		GetWorld()->LineTraceMultiByChannel(OutHits, Start, End, ECollisionChannel(ECC_Pawn), CollisionParams);

		if (OutHits.Num() > 0 && OutHits[0].GetActor())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Self: %s"), *WeaponMuzzle->GetForwardVector().ToString());
			//UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *OutHits[0].GetActor()->GetActorLocation().ToString());
			FVector HitActorLocation = OutHits[0].GetActor()->GetActorLocation();
			float HitDistX = FMath::Abs(HitActorLocation.X - Start.X);
			float HitDistY = FMath::Abs(HitActorLocation.Y - Start.Y);
			float DistX = FMath::Abs(WeaponMuzzle->GetForwardVector().X * HitDistX);
			float DistY = FMath::Abs(WeaponMuzzle->GetForwardVector().Y * HitDistY);

			LaserSightDistance = DistX + DistY;
			//LaserSightDistance = ((DistX + DistY) < (HitActorLocation - Start).Size()) ? DistX + DistY : (HitActorLocation - Start).Size();
		}

		End = LaserSight->GetForwardVector() * LaserSightDistance + LaserSight->GetComponentLocation();

		LaserSight->SetBeamSourcePoint(0, Start, 0);
		LaserSight->SetBeamTargetPoint(0, End, 0);
	}
}

void AMinibossBlue::Fire()
{
	if (Sniper)
	{
		Sniper->Fire(WeaponMuzzle);
	}
}

void AMinibossBlue::Reload()
{
	if (Sniper)
	{
		if (Sniper->CanTheWeaponReload())
		{
			if (ReloadAnimation)
			{
				GetMesh()->GetAnimInstance()->Montage_Play(ReloadAnimation, ReloadAnimation->SequenceLength / Sniper->ReloadSpeed);
				DisableLaserSight(Sniper->ReloadSpeed);
			}
		}

		Sniper->Reload();
	}
}

void AMinibossBlue::DisableLaserSight(float Duration)
{
	if (LaserSight)
	{
		LaserSight->SetVisibility(false);
	}

	GetWorldTimerManager().SetTimer(LaserSightTimerHandle, this, &AMinibossBlue::EnableLaserSight, Duration, false);
}

void AMinibossBlue::EnableLaserSight()
{
	if (LaserSight)
	{
		LaserSight->SetVisibility(true);
	}

	GetWorldTimerManager().ClearTimer(LaserSightTimerHandle);
}