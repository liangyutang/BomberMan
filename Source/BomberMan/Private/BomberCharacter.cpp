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

float ABomberCharacter::GetSnappedValue(int Value, float Scale)
{
	const int Remains= Value%static_cast<int>(Scale);

	//��������
	return FMath::Abs(Remains) > Scale / 2?Value-Remains+(Value<0?-Scale:Scale):Value-Remains;
}

FVector ABomberCharacter::GetSnappedPosition(FVector SourcePos)
{

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
		//�������ӵ����
		FActorSpawnParameters Parameters;
		Parameters.Owner = this;
		GetWorld()->SpawnActor<ABomb>(Bomb, GetActorLocation(), FRotator::ZeroRotator,Parameters);
	}
}

