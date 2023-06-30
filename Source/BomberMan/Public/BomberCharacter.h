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


	//�����и����Ƿŵ�ը��
	UPROPERTY()
	TArray<class ABomb*> PlacedBombs;

protected:

	UPROPERTY(EditAnywhere,Category="Bomb")
	TSubclassOf<class ABomb> Bomb;

	int InitialBlastRange = 1;

	int InitialBombLimit = 1;

	float InitialMaxWalkSpeed = 450.0f;

	//������ը��Χ
	int BlastRange;

	//���԰ڷŵ�ը������
	int BombLimit;

	bool bHasRemote = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**
	 * @brief ����ը����ש����
	 * @param Value ��ǰλ��
	 * @param Scale ש���С
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
