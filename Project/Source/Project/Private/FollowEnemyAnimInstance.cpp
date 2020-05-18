// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowEnemyAnimInstance.h"

void UFollowEnemyAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
	if (Pawn)
	{
		FollowEnemy = Cast<AJFollowEnemy>(Pawn);
	}

}

void UFollowEnemyAnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
	if (Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();
		FollowEnemy = Cast<AJFollowEnemy>(Pawn);
	}
	
}
