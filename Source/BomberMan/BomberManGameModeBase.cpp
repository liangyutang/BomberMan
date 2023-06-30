// Copyright Epic Games, Inc. All Rights Reserved.


#include "BomberManGameModeBase.h"

#include "BomberCharacter.h"
#include "BomberPlayerController.h"
#include "Kismet/KismetStringLibrary.h"

ABomberManGameModeBase::ABomberManGameModeBase()
{

	PrimaryActorTick.bCanEverTick = true;

	DefaultPawnClass = ABomberCharacter::StaticClass();
	PlayerControllerClass = ABomberPlayerController::StaticClass();
}

void ABomberManGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//µ¹¼ÆÊ±
	TotalTime -= DeltaSeconds;
	UKismetStringLibrary::TimeSecondsToString(TotalTime);
}
