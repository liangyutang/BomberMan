// Fill out your copyright notice in the Description page of Project Settings.


#include "BomberPlayerController.h"

#include "BomberCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


void ABomberPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	const int32 Id= GetLocalPlayer()->GetControllerId();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (Id == 0)
		{
			Subsystem->AddMappingContext(IMC_Move, Id);
		}
		if (Id == 1)
		{
			Subsystem->AddMappingContext(IMC_Move2, Id);
		}
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		if (IA_MoveHorizontal)
		{
			EnhancedInputComponent->BindAction(IA_MoveHorizontal, ETriggerEvent::Triggered, this, &ABomberPlayerController::MoveHorizontal);
		}


		if (IA_MoveVertical)
		{
			EnhancedInputComponent->BindAction(IA_MoveVertical, ETriggerEvent::Triggered, this, &ABomberPlayerController::MoveVertical);
		}

		if (IA_SpawnBomb)
		{
			EnhancedInputComponent->BindAction(IA_SpawnBomb, ETriggerEvent::Started, this, &ABomberPlayerController::SpawnBombInput);
		}
	}
	
}

void ABomberPlayerController::BeginPlay()
{
	Super::BeginPlay();
}


void ABomberPlayerController::MoveVertical(const FInputActionValue& InputValue)
{
	const float Value = InputValue.GetMagnitude();

	NowPawn = GetPawn();
	if (NowPawn)
	{
		NowPawn->AddMovementInput(FVector::RightVector, Value);
	}
}

void ABomberPlayerController::MoveHorizontal(const FInputActionValue& InputValue)
{
	const float Value = InputValue.GetMagnitude();

	NowPawn = GetPawn();
	if (NowPawn)
	{
		NowPawn->AddMovementInput(FVector::ForwardVector, Value);
	}
}

void ABomberPlayerController::SpawnBombInput()
{
	NowPawn = GetPawn();
	if (NowPawn)
	{
		if (ABomberCharacter* BombPlayer= Cast<ABomberCharacter>(NowPawn))
		{
			BombPlayer->SpawnBomb();
		}
	}
}
