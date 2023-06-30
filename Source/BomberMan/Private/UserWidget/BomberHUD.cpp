// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidget/BomberHUD.h"

#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"

bool UBomberHUD::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	//绑定点击事件
	RestartButton->OnClicked.AddDynamic(this, &UBomberHUD::OnRestartButtonClicked);

	return true;
}

void UBomberHUD::OnRestartButtonClicked()
{

}

void UBomberHUD::SetRemainTimer(const FText& TimerText)
{
	RemainTimer->SetText(TimerText);
}

void UBomberHUD::SetP1Text(const int Score)
{
	P1_Text->SetText(FText::AsNumber(Score));
}
void UBomberHUD::SetP2Text(const int Score)

{
	P2_Text->SetText(FText::AsNumber(Score));
}

void UBomberHUD::SetWinTitle(const FText& WinPlayerText)
{
	WinTitle->SetText(WinPlayerText);
}

void UBomberHUD::SetMenuBackgroundVisible()
{
	MenuBackground->SetVisibility(ESlateVisibility::Visible);
}
