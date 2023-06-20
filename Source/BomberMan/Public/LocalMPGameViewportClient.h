// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Engine/GameViewportClient.h"
#include "LocalMPGameViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ULocalMPGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

protected:
	virtual bool InputKey(const FInputKeyEventArgs& EventArgs) override;

	virtual bool InputAxis(FViewport* Viewport1, FInputDeviceId InputDevice, FKey Key, float Delta, float DeltaTime, int32 NumSamples, bool bGamepad) override;
};
