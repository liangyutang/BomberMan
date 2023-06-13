// Fill out your copyright notice in the Description page of Project Settings.


#include "BomberPlayerController.h"

#include "BomberCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


void ABomberPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (const APlayerController* PlayerController = CastChecked<APlayerController>(this))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(IMC_Move, 0);
			Subsystem->AddMappingContext(IMC_Move2, 1);
		}
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(this))
	{
		if (IA_MoveHorizontal)
		{
			EnhancedInputComponent->BindAction(IA_MoveHorizontal, ETriggerEvent::Triggered, this, &ABomberPlayerController::MoveHorizontal);
		}

		if (IA_MoveVertical)
		{
			EnhancedInputComponent->BindAction(IA_MoveVertical, ETriggerEvent::Triggered, this, &ABomberPlayerController::MoveVertical);
		}
	}
}

void ABomberPlayerController::BeginPlay()
{
	Super::BeginPlay();
	Pawn = GetPawn();
}


void ABomberPlayerController::MoveVertical(const FInputActionValue& InputValue)
{
	const float Value = InputValue.GetMagnitude();
	
	if (Pawn)
	{
		Pawn->AddMovementInput(FVector::RightVector, Value);
	}
}

void ABomberPlayerController::MoveHorizontal(const FInputActionValue& InputValue)
{
	const float Value = InputValue.GetMagnitude();

	if (Pawn)
	{
		Pawn->AddMovementInput(FVector::ForwardVector, Value);
	}
}
