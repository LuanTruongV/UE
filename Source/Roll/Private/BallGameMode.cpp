// Fill out your copyright notice in the Description page of Project Settings.


#include "BallGameMode.h"

#include "BallBearingHUD.h"

ABallGameMode::ABallGameMode()
{
	PrimaryActorTick.bCanEverTick=true;
	HUDClass=ABallBearingHUD::StaticClass();
}

