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
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* RemainTimer;


};
