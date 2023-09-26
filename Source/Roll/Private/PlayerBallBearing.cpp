// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBallBearing.h"

#include "GameFramework/PlayerInput.h"


APlayerBallBearing::APlayerBallBearing()
{
	SpringArm=CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->bDoCollisionTest=false;
	SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->SetRelativeRotation(FRotator(-45.f,0.0f,0.f));
	SpringArm->TargetArmLength=100.f;
	SpringArm->bEnableCameraLag=false;
	SpringArm->SetupAttachment(BallMesh);

	Camera=CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->bUsePawnControlRotation=false;
	Camera->SetupAttachment(SpringArm,USpringArmComponent::SocketName);
	Magnetized=false;
	
	
}
static void InitializeDefaultPawnInputBinding()
{
	static bool bindingsAdded=false;
	if(bindingsAdded==false)
	{
		bindingsAdded=true;
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLongitudinally",EKeys::W,1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLongitudinally",EKeys::S,-1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLongitudinally",EKeys::Up,1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLongitudinally",EKeys::Down,-1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLongitudinally",EKeys::Gamepad_LeftY,-1.f));
		

		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLaterally",EKeys::D,1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLaterally",EKeys::A,-1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLaterally",EKeys::Right,1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLaterally",EKeys::Left,-1.f));
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLaterally",EKeys::Gamepad_LeftX,1.f));

		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("BallBearing_Jump",EKeys::Enter));
		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("BallBearing_Dash",EKeys::SpaceBar));
	
	}	
}
void APlayerBallBearing::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent!=nullptr);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InitializeDefaultPawnInputBinding();
	PlayerInputComponent->BindAxis("BallBearing_MoveLongitudinally",this,&APlayerBallBearing::MoveLongitudinally);
	PlayerInputComponent->BindAxis("BallBearing_MoveLaterally",this,&APlayerBallBearing::MoveLaterally);
	PlayerInputComponent->BindAction("BallBearing_Jump",IE_Pressed,this,&APlayerBallBearing::Jump);
	PlayerInputComponent->BindAction("BallBearing_Dash",IE_Pressed,this,&APlayerBallBearing::Dash);

	
}
void APlayerBallBearing::Jump()
{
	
}
void APlayerBallBearing::Dash()
{
	
}
void APlayerBallBearing::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	BallMesh->AddForce(FVector(InputLongitude,InputLatitude,0.0f)*ControllerForce*BallMesh->GetMass());
}




