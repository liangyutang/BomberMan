// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockGenerator.h"

#include "UnbreakableBlock.h"

// Sets default values
ABlockGenerator::ABlockGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IgnorePos.Add(FVector(700.0f, -700.0f, 0.0f));
	IgnorePos.Add(FVector(-700.0f, 700.0f, 0.0f));
}

// Called when the game starts or when spawned
void ABlockGenerator::BeginPlay()
{
	Super::BeginPlay();

	SpawnUnbreakableBlock();
	
}

void ABlockGenerator::SpawnUnbreakableBlock()
{
	for (int i=0;i<Width;i++)
	{
		for (int j = 0; j < Height; j++)
		{
			if (i%2!=0 && j%2!=0)
			{
				//Éú³ÉÎ»ÖÃ
				FVector SpawnLocation = FVector(i-7, j-7, 0) * Scale;

				GetWorld()->SpawnActor<AUnbreakableBlock>(UnbreakableBlock,SpawnLocation,FRotator::ZeroRotator);
			}
		}
	}
}

bool ABlockGenerator::AllowedSpawnPosition(FVector Position)
{
}

void ABlockGenerator::FindValidPosition()
{
}

// Called every frame
void ABlockGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

