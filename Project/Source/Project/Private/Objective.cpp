// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective.h"

void AObjective::UpdateProgress()
{
	Progress++;
	if (Progress >= Requirement)
	{
		bComplete = true;
	}
}