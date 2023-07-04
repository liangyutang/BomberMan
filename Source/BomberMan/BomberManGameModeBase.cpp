// Copyright Epic Games, Inc. All Rights Reserved.


#include "BomberManGameModeBase.h"

#include "BomberCharacter.h"
#include "BomberPlayerController.h"
#include "BomberSaveGame.h"
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

	//创建存储文件
	BomberSaveInstance = Cast<UBomberSaveGame>( UGameplayStatics::CreateSaveGameObject(UBomberSaveGame::StaticClass()));
}

void ABomberManGameModeBase::IncrementP1Victories()
{
	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName,UserIndex))
	{
		//加载存储文件
		BomberSaveInstance= Cast<UBomberSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName,UserIndex));
	}
	else
	{
		//没有找到存储文件，则创建
		BomberSaveInstance = Cast<UBomberSaveGame>(UGameplayStatics::CreateSaveGameObject(UBomberSaveGame::StaticClass()));
	}

	BomberSaveInstance->IncreaseP1Victories();
	UGameplayStatics::SaveGameToSlot(BomberSaveInstance, SaveSlotName, UserIndex);
}

//P2加分
void ABomberManGameModeBase::IncrementP2Victories()
{
	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, UserIndex))
	{
		//加载存储文件
		BomberSaveInstance = Cast<UBomberSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, UserIndex));
	}
	else
	{
		//没有找到存储文件，则创建
		BomberSaveInstance = Cast<UBomberSaveGame>(UGameplayStatics::CreateSaveGameObject(UBomberSaveGame::StaticClass()));
	}
	BomberSaveInstance->IncreaseP2Victories();

	UGameplayStatics::SaveGameToSlot(BomberSaveInstance, SaveSlotName, UserIndex);

}

void ABomberManGameModeBase::UpdateScore()
{
	OnGameEnd();
	BomberHUD->SetP1Text(BomberSaveInstance->GetP1Victories());
	BomberHUD->SetP2Text(BomberSaveInstance->GetP2Victories());
}

void ABomberManGameModeBase::OnGameEnd()
{
	UGameplayStatics::SetGamePaused(this, true);
	UGameplayStatics::GetPlayerController(this, 0)->bShowMouseCursor = true;
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
		IncrementP2Victories();

	}
	else if (UGameplayStatics::GetPlayerControllerID(BomberPlayerController) == 1)
	{
		BomberHUD->SetWinTitle(Player1WinText);
		IncrementP1Victories();
	}
	UpdateScore();
	BomberHUD->SetMenuBackgroundVisible();
}

void ABomberManGameModeBase::Restart()
{
	//销毁玩家1
	UGameplayStatics::RemovePlayer(UGameplayStatics::GetPlayerController(this, 1),Destroy());

	UGameplayStatics::OpenLevel(this, "Level01");
}
