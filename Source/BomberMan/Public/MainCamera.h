// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "MainCamera.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API AMainCamera : public ACameraActor
{
	GENERATED_BODY()

public:

protected:
	UPROPERTY()
	APlayerController* PC;

protected:
	virtual void BeginPlay() override;
};
