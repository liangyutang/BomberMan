// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BomberManGameModeBase.generated.h"

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

public:
	FORCEINLINE float GetDropChance() const { return DropChance; }
};
