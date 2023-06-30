// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BomberManGameModeBase.generated.h"

enum class EPowerupType:uint8
{
	SpeedBoost,//���ٶ�
	MoreBombs,//�ڷ�����
	LongerBlast,//��ը��Χ
	RemoteBomb//��ʱը��
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
	//���ߵ��伸��

	UPROPERTY(EditAnywhere,Category="Powerup", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float DropChance = 0.4f;

	//��Ϸ��ʱ�䣬300��
	UPROPERTY(EditAnywhere,Category="Time")
	float TotalTime = 300.f;

	UPROPERTY(VisibleAnywhere,Category="Time")
	FText TimeText;

	//��HUD
	UPROPERTY(EditAnywhere,Category="HUD")
	class UBomberHUD* BomberHUD;
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;

	FORCEINLINE float GetDropChance() const { return DropChance; }

	void OnPlayerDeath(AController* Controller);
};
