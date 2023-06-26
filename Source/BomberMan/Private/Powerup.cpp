// Fill out your copyright notice in the Description page of Project Settings.


#include "Powerup.h"

#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APowerup::APowerup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetupAttachment(RootComponent);

	Billboard = CreateDefaultSubobject<UBillboardComponent>("Billboard");
	Billboard->SetupAttachment(BoxCollision);
	Billboard->SetHiddenInGame(false);
}

// Called when the game starts or when spawned
void APowerup::BeginPlay()
{
	Super::BeginPlay();

	//ÉèÖÃÌùÍ¼
	Billboard->SetSprite(Sprites[FMath::RandRange(0, 3)]);
}

// Called every frame
void APowerup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

