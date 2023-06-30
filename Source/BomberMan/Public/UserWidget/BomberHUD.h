// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BomberHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API UBomberHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	//meta = (BindWidget):绑定蓝图中的同名Widget,
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* RemainTimer;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* WinTitle;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* P1_Text;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* P2_Text;

	UPROPERTY(meta = (BindWidget))
	class UButton* RestartButton;

	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* MenuBackground;
	
protected:
	virtual bool Initialize() override;

	UFUNCTION()
	void OnRestartButtonClicked();

public:
	void SetRemainTimer(const FText& TimerText);

	void SetP1Text(int Score);

	void SetP2Text(int Score);

	void SetWinTitle(const FText& WinPlayerText);

	void SetMenuBackgroundVisible();
};
