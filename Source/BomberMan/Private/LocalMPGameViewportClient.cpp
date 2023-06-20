// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalMPGameViewportClient.h"



bool ULocalMPGameViewportClient::InputKey(const FInputKeyEventArgs& EventArgs)
{
	if (IgnoreInput()||EventArgs.IsGamepad()||EventArgs.Key.IsMouseButton())
	{
		return Super::InputKey(EventArgs);
	}
	else
	{
		UEngine* const Engine = GetOuterUEngine();
		int32 const NumPlayers = Engine ? Engine->GetNumGamePlayers(this) : 0;
		bool bRetVal = true;
		for (int32 i=0;i<NumPlayers;i++)
		{
			FInputKeyEventArgs InputKeyEventArgs = FInputKeyEventArgs(EventArgs);
			InputKeyEventArgs.ControllerId = i;
			bRetVal=Super::InputKey(InputKeyEventArgs)&& bRetVal;
		}
		return bRetVal;
	}
}

//bool ULocalMPGameViewportClient::InputAxis(FViewport* Viewport1, int32 ControllerId, FKey Key, float Delta,
//	float DeltaTime, int32 NumSamples, bool bGamepad)
//{
//
//	if (IgnoreInput() || bGamepad || Key.IsMouseButton())
//	{
//		return Super::InputAxis(Viewport1, ControllerId, Key, Delta, DeltaTime, NumSamples, bGamepad);
//	}
//	else
//	{
//		UEngine* const Engine = GetOuterUEngine();
//		int32 const NumPlayers = Engine ? Engine->GetNumGamePlayers(this) : 0;
//		bool bRetVal = true;
//		for (int32 i = 0; i < NumPlayers; i++)
//		{
//			bRetVal =Super::InputAxis(Viewport1, i, Key, Delta, DeltaTime, NumSamples, bGamepad)&& bRetVal;
//		}
//		return bRetVal;
//	}
//}

bool ULocalMPGameViewportClient::InputAxis(FViewport* Viewport1, FInputDeviceId InputDevice, FKey Key, float Delta,
	float DeltaTime, int32 NumSamples, bool bGamepad)
{
	if (IgnoreInput() || bGamepad || Key.IsMouseButton())
	{
		return Super::InputAxis(Viewport1, InputDevice, Key, Delta, DeltaTime, NumSamples, bGamepad);
	}
	else
	{
		UEngine* const Engine = GetOuterUEngine();
		int32 const NumPlayers = Engine ? Engine->GetNumGamePlayers(this) : 0;
		bool bRetVal = true;
		for (int32 i = 0; i < NumPlayers; i++)
		{
			bRetVal = Super::InputAxis(Viewport1, FInputDeviceId::CreateFromInternalId(i), Key, Delta, DeltaTime, NumSamples, bGamepad) && bRetVal;
		}
		return bRetVal;
	}

	
}
