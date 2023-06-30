// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidget/BomberHUD.h"

#include "Components/TextBlock.h"

void UBomberHUD::SetRemainTimer(FText TimerText)
{
	RemainTimer->SetText(TimerText);
}
