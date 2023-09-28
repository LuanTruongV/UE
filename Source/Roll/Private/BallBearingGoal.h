// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BallBearing.h"
#include "Engine/TriggerSphere.h"
#include "BallBearingGoal.generated.h"

/**
 * 
 */
UCLASS()
class ABallBearingGoal : public ATriggerSphere
{
	GENERATED_BODY()
public: 
	ABallBearingGoal();
protected:
	virtual void PostInitializeComponents() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
private:
	UPROPERTY(Transient)
	TArray<ABallBearing*> BallBearings;
};
