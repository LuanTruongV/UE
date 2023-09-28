// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CanvasItem.h"
#include "Engine/Canvas.h"
#include "GameFramework/HUD.h"
#include "DebugHUD.generated.h"

/**
 * 
 */
UCLASS()
class ADebugHUD : public AHUD
{
	GENERATED_BODY()
protected:
	ADebugHUD();

	void AddText(const TCHAR* title, const FText& value)
	{
		RenderStatistic(title,value);
	}
	void AddFloat(const TCHAR* title,float value)
	{
		RenderStatistic(title,FText::AsNumber(value));
	}
	void AddInt(const TCHAR* title,int value)
	{
		RenderStatistic(title,FText::AsNumber(value));
	}
	void AddBool(const TCHAR* title,bool value)
	{
		RenderStatistic(title,BoolToText(value),value==false ? FLinearColor::Red:FLinearColor::Green);
	}
	virtual void DrawHUD()override
	{
		X=Y=50.f;
	};
	float HorizontalOffset=150.f;
private:
	FText CStringToText(const TCHAR* text)
	{
		return FText::FromString(text);
	}
	FText BoolToText(bool value)
	{
		return CStringToText((value==true) ? TEXT("true") : TEXT("false"));
	}
	void RenderStatistic(const TCHAR* title,const FText& value,const FLinearColor& valueColor= FLinearColor::White)
	{
		FCanvasTextItem item0(FVector2d(X,Y),CStringToText(title),MainFont,FLinearColor::Black);
		item0.EnableShadow(FLinearColor(0.f,0.f,0.f));
		Canvas->DrawItem(item0);
		FCanvasTextItem item1(FVector2d(X+HorizontalOffset,Y),value,MainFont,valueColor);
		item1.EnableShadow(FLinearColor(0.f,0.f,0.f));
		Canvas->DrawItem(item1);
		Y+=LineHeight;
	};
	UPROPERTY(Transient)
	UFont* MainFont=nullptr;
	float X=50.f;
	float Y=50.f;
	float LineHeight=16.f;
	
};
