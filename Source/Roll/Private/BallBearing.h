// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "BallBearing.generated.h"

UCLASS()
class ABallBearing : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABallBearing();
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=BallBearing)
	UStaticMeshComponent* BallMesh=nullptr;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=BallBearing)
	bool Magnetized=true;
	UFUNCTION(BlueprintCallable)
	void ResetLocation() const	
	{
		BallMesh->SetWorldLocation(InitialLocation+FVector(0.f,0.f,150.f));
		BallMesh->SetPhysicsLinearVelocity(FVector::ZeroVector);
		BallMesh->SetPhysicsAngularVelocityInDegrees(FVector::ZeroVector);
	}
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override
	{
		Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
		InContact=true;
	}
	bool InContact=false;

private:
	FVector InitialLocation=FVector::ZeroVector;
	friend class ABallBearingHUD;
};
