// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakableBlock.h"

#include "Powerup.h"
#include "BomberMan/BomberManGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABreakableBlock::ABreakableBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BreakableBlock = CreateDefaultSubobject<UStaticMeshComponent>("BreakableBlock");
	BreakableBlock->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABreakableBlock::BeginPlay()
{
	Super::BeginPlay();

	BomberManGameMode =Cast<ABomberManGameModeBase>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void ABreakableBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABreakableBlock::OnDestroy()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Explosion, GetActorLocation(), GetActorRotation());

	if (FMath::RandRange(0.0f,1.0f)<BomberManGameMode->GetDropChance())
	{
		GetWorld()->SpawnActor<APowerup>(Powerup, GetActorLocation(), GetActorRotation());
	}
	Destroy();
}

