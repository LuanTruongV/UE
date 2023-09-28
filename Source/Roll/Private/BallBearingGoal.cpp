// Fill out your copyright notice in the Description page of Project Settings.


#include "BallBearingGoal.h"

#include "Components/BillboardComponent.h"
#include "Components/ShapeComponent.h"

ABallBearingGoal::ABallBearingGoal()
{
	SetActorHiddenInGame(false);
}
void ABallBearingGoal::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	GetCollisionComponent()->SetHiddenInGame(true);
#if WITH_EDITORONLY_DATA
	GetSpriteComponent()->SetHiddenInGame((true));
#endif
}

void ABallBearingGoal::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	ABallBearing* ballBearing=Cast<ABallBearing>(OtherActor);
	if(ballBearing!=nullptr && ballBearing->Magnetized==true)
	{
		BallBearings.AddUnique(ballBearing);
	}
}

void ABallBearingGoal::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	ABallBearing* ballBearing=Cast<ABallBearing>(OtherActor);
	if(ballBearing!=nullptr && ballBearing->Magnetized==true)
	{
		BallBearings.Remove(ballBearing);
	}
}





