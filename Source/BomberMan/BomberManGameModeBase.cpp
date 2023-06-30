// Copyright Epic Games, Inc. All Rights Reserved.


#include "BomberManGameModeBase.h"

#include "BomberCharacter.h"
#include "BomberPlayerController.h"
#include "Kismet/GameplayStatics.h"
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

void ABomberManGameModeBase::OnPlayerDeath(AController* Controller)
{
	ABomberPlayerController* BomberPlayerController= Cast<ABomberPlayerController>(Controller);

	const FText Player1WinText = FText::FromString("Player 1 Win!");
	const FText Player2WinText = FText::FromString("Player 2 Win!");

	if (UGameplayStatics::GetPlayerControllerID(BomberPlayerController)==0)
	{
		BomberHUD->SetWinTitle(Player2WinText);

	}
	else if (UGameplayStatics::GetPlayerControllerID(BomberPlayerController) == 1)
	{
		BomberHUD->SetWinTitle(Player1WinText);
	}

	BomberHUD->SetMenuBackgroundVisible();
}
