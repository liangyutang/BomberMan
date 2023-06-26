// Fill out your copyright notice in the Description page of Project Settings.


#include "Powerup.h"

#include "BomberCharacter.h"
#include "Components/BillboardComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

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
	int TempRand = FMath::RandRange(0, 3);
	PowerupType =StaticCast<EPowerupType>(TempRand);

	//ÉèÖÃÌùÍ¼
	Billboard->SetSprite(Sprites[TempRand]);
}

// Called every frame
void APowerup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APowerup::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (ABomberCharacter* BomberCharacter =Cast<ABomberCharacter>(OtherActor))
	{
		switch (PowerupType)
		{
		case EPowerupType::SpeedBoost:
			BomberCharacter->GetCharacterMovement()->MaxWalkSpeed += SpeedBoost;
			break;
		case EPowerupType::MoreBombs:
			BomberCharacter->IncreaseBombLimit();
			break;
		case EPowerupType::LongerBlast: 
			BomberCharacter->IncreaseBlastRange(BlastRangeBoost);
			break;
		case EPowerupType::RemoteBomb: break;
		default: ;
		}
		Destroy();
	}
	
}

