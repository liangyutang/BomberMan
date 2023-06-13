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

	//备选的合法位置
	UPROPERTY(VisibleAnywhere,Category="Block Generation|Setting")
	TArray<FVector> SpawnPoints;

	//忽略的位置，不产生障碍物，用来生成主角
	UPROPERTY(EditAnywhere, Category = "Block Generation|Setting")
	TArray<FVector> IgnorePos;

	const FLinearColor ValidColor = FLinearColor(0, 0, 0.8f);

	const FLinearColor InValidColor = FLinearColor(0.8f, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Block Generation|Debug")
	bool bDrawDebugPoint = true;
protected:
	// Called when the game starts or when spawne
	virtual void BeginPlay() override;

	void SpawnUnbreakableBlock();

	bool AllowedSpawnPosition(FVector Position);

	UFUNCTION(BlueprintCallable)
	void FindValidPosition();

	void DrawDebugPoint(FVector& Center, const FLinearColor& Color);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual bool ShouldTickIfViewportsOnly() const override;
};
