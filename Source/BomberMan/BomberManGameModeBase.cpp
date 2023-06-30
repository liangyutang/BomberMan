// Copyright Epic Games, Inc. All Rights Reserved.


#include "BomberManGameModeBase.h"

#include "BomberCharacter.h"
#include "BomberPlayerController.h"
#include "Kismet/KismetStringLibrary.h"
#include "UserWidget/BomberHUD.h"

ABomberManGameModeBase::ABomberManGameModeBase()
{

	PrimaryActorTick.bCanEverTick = true;

	DefaultPawnClass = ABomberCharacter::StaticClass();
	PlayerControllerClass = ABomberPlayerController::StaticClass();
}

void ABomberManGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//创建HUD
	BomberHUD=CreateWidget<UBomberHUD>(GetWorld(), LoadClass<UBomberHUD>(this, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/WBP_HUD.WBP_HUD_C'")));
	BomberHUD->AddToViewport();
}

void ABomberManGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//倒计时
	TotalTime -= DeltaSeconds;
	TimeText=FText::FromString(UKismetStringLibrary::TimeSecondsToString(TotalTime));
	BomberHUD->SetRemainTimer(TimeText);
	
}
