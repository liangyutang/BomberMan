// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockGenerator.h"

#include "UnbreakableBlock.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ABlockGenerator::ABlockGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = WITH_EDITOR;

	IgnorePos.Add(FVector(700.0f, -700.0f, 0.0f));
	IgnorePos.Add(FVector(700.0f, -600.0f, 0.0f));
	IgnorePos.Add(FVector(600.0f, -700.0f, 0.0f));

	IgnorePos.Add(FVector(-700.0f, 700.0f, 0.0f));
	IgnorePos.Add(FVector(-700.0f, 600.0f, 0.0f));
	IgnorePos.Add(FVector(-600.0f, 700.0f, 0.0f));

}

// Called when the game starts or when spawned
void ABlockGenerator::BeginPlay()
{
	Super::BeginPlay();

	SpawnUnbreakableBlock();

	FindValidPosition();

	bDrawDebugPoint = false;
	
}

void ABlockGenerator::SpawnUnbreakableBlock()
{
	for (int i=0;i<Width;i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if (i%2!=0 && j%2!=0)
			{
				//生成位置
				FVector SpawnLocation = FVector(i-7, j-7, 0) * Scale;

				GetWorld()->SpawnActor<AUnbreakableBlock>(UnbreakableBlock,SpawnLocation,FRotator::ZeroRotator);
			}
		}
	}
}

bool ABlockGenerator::AllowedSpawnPosition(FVector Position)
{
	if (IgnorePos.Contains(Position))
	{
		return false;
	}

	return true;
}

void ABlockGenerator::FindValidPosition()
{
	if (SpawnPoints.Num()>0)
	{
		SpawnPoints.Empty();
	}

	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if (i % 2 == 0 || j % 2 == 0)
			{
				//生成位置
				FVector SpawnLocation = FVector(i - 7, j - 7, 0) * Scale;
				if (AllowedSpawnPosition(SpawnLocation))
				{
					SpawnPoints.Add(SpawnLocation);
				}
			}
		}
	}
}

void ABlockGenerator::DrawDebugPoint(FVector& Center, const FLinearColor& Color)
{
	UKismetSystemLibrary::DrawDebugPoint(this, Center, 20.0f, Color);
}

// Called every frame
void ABlockGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (bDrawDebugPoint)
	{
		for (FVector& SpawnPoint : SpawnPoints)
		{
			DrawDebugPoint(SpawnPoint, ValidColor);
		}

		for (FVector& IgnorePo : IgnorePos)
		{
			DrawDebugPoint(IgnorePo, InValidColor);
		}
	}
}

bool ABlockGenerator::ShouldTickIfViewportsOnly() const
{
	return WITH_EDITOR;
}

