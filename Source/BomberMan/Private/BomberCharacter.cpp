// Fill out your copyright notice in the Description page of Project Settings.


#include "BomberCharacter.h"

#include "Bomb.h"

// Sets default values
ABomberCharacter::ABomberCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABomberCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void ABomberCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ABomberCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABomberCharacter::SpawnBomb()
{
	if (Bomb)
	{
		//生成物的拥有者
		FActorSpawnParameters Parameters;
		Parameters.Owner = this;
		GetWorld()->SpawnActor<ABomb>(Bomb, GetActorLocation(), FRotator::ZeroRotator,Parameters);
	}
}

