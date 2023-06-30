// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "BomberCharacter.generated.h"

UCLASS()
class BOMBERMAN_API ABomberCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABomberCharacter();


	//场景中该主角放的炸弹
	UPROPERTY()
	TArray<class ABomb*> PlacedBombs;

protected:

	UPROPERTY(EditAnywhere,Category="Bomb")
	TSubclassOf<class ABomb> Bomb;

	int InitialBlastRange = 1;

	int InitialBombLimit = 1;

	float InitialMaxWalkSpeed = 450.0f;

	//单方向爆炸范围
	int BlastRange;

	//可以摆放的炸弹数量
	int BombLimit;

	bool bHasRemote = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**
	 * @brief 修正炸弹到砖块上
	 * @param Value 当前位置
	 * @param Scale 砖块大小
	 * @return 
	 */
	float GetSnappedValue(int Value, float Scale);

	FVector GetSnappedPosition(FVector SourcePos);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SpawnBomb();

	void IncreaseBlastRange(float BlastRangeBoost) { this->BlastRange += BlastRange; }

	void IncreaseBombLimit() { BombLimit++; }

	void SetHasRemoteTrue() { bHasRemote = true; }

	FORCEINLINE bool GetBHasRemote() const { return bHasRemote; }

	void ResetInitial();
private:


};
