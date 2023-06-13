// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlockGenerator.generated.h"

UCLASS()
class BOMBERMAN_API ABlockGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockGenerator();

protected:

	UPROPERTY(EditAnywhere, Category = "Block Generation")
	TSubclassOf <class  AUnbreakableBlock > UnbreakableBlock;

	UPROPERTY(EditAnywhere, Category = "Block Generation")
	TSubclassOf <class  ABreakableBlock > BreakableBlock;

	UPROPERTY(EditAnywhere, Category = "Block Generation|Setting")
	int Height = 15;

	UPROPERTY(EditAnywhere, Category = "Block Generation|Setting")
	int Width = 15;

	UPROPERTY(EditAnywhere, Category = "Block Generation|Setting")
	float Scale = 100.0f;

	//��ѡ�ĺϷ�λ��
	UPROPERTY(VisibleAnywhere,Category="Block Generation|Setting")
	TArray<FVector> SpawnPoints;

	//���Ե�λ�ã��������ϰ��������������
	UPROPERTY(EditAnywhere, Category = "Block Generation|Setting")
	TArray<FVector> IgnorePos;
protected:
	// Called when the game starts or when spawne
	virtual void BeginPlay() override;

	void SpawnUnbreakableBlock();

	bool AllowedSpawnPosition(FVector Position);

	void FindValidPosition();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
