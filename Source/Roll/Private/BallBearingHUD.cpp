// Fill out your copyright notice in the Description page of Project Settings.


#include "BallBearingHUD.h"

#include "PlayerBallBearing.h"

void ABallBearingHUD::DrawHUD()
{
	Super::DrawHUD();
	APlayerBallBearing* BallBearing=Cast<APlayerBallBearing>(GetOwningPawn());
	if(BallBearing!=nullptr)
	{
		AddFloat(L"Speed",BallBearing->GetVelocity().Size()/100.f);
		AddFloat(L"DashTime",BallBearing->DashTimer);
		AddFloat(L"Input Latitude",BallBearing->InputLatitude);
		AddFloat(L"Input Longitude",BallBearing->InputLongitude);
	}
}
