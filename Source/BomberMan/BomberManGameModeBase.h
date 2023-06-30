// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BomberManGameModeBase.generated.h"

enum class EPowerupType:uint8
{
	SpeedBoost,//加速度
	MoreBombs,//摆放数量
	LongerBlast,//爆炸范围
	RemoteBomb//定时炸弹
};

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABomberManGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABomberManGameModeBase();
protected:
	//道具掉落几率

	UPROPERTY(EditAnywhere,Category="Powerup", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float DropChance = 0.4f;

	//游戏总时间，300秒
	UPROPERTY(EditAnywhere,Category="Time")
	float TotalTime = 300.f;

	UPROPERTY(VisibleAnywhere,Category="Time")
	FText TimeText;

	//绑定HUD
	UPROPERTY(EditAnywhere,Category="HUD")
	class UBomberHUD* BomberHUD;
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;

	FORCEINLINE float GetDropChance() const { return DropChance; }

	void OnPlayerDeath(AController* Controller);
};
