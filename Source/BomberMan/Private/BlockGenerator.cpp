// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockGenerator.h"

// Sets default values
ABlockGenerator::ABlockGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlockGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlockGenerator::SpawnUnbreakableBlock()
{
}

// Called every frame
void ABlockGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

