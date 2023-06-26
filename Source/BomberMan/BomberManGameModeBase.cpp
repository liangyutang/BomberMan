// Copyright Epic Games, Inc. All Rights Reserved.


#include "BomberManGameModeBase.h"

#include "BomberCharacter.h"
#include "BomberPlayerController.h"

ABomberManGameModeBase::ABomberManGameModeBase()
{
	DefaultPawnClass = ABomberCharacter::StaticClass();
	PlayerControllerClass = ABomberPlayerController::StaticClass();
}
