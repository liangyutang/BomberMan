// Fill out your copyright notice in the Description page of Project Settings.


#include "BomberCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
ABomberCharacter::ABomberCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABomberCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABomberCharacter::MoveVertical(const FInputActionValue& InputValue)
{
	float Value = InputValue.GetMagnitude();
	AddMovementInput(FVector::RightVector, Value);
}

void ABomberCharacter::MoveHorizontal(const FInputActionValue& InputValue)
{
	float Value = InputValue.GetMagnitude();
	AddMovementInput(FVector::ForwardVector,Value);
}

// Called every frame
void ABomberCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ABomberCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

