// Fill out your copyright notice in the Description page of Project Settings.


#include "BomberCharacter.h"

#include "Bomb.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ABomberCharacter::ABomberCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->MaxWalkSpeed = 450.f;
}

// Called when the game starts or when spawned
void ABomberCharacter::BeginPlay()
{
	Super::BeginPlay();

	//定义一些初始数据
	BombLimit = InitialBombLimit;
	BlastRange = InitialBlastRange;
	GetCharacterMovement()->MaxWalkSpeed = InitialMaxWalkSpeed;
	
}

float ABomberCharacter::GetSnappedValue(int Value, float Scale)
{
	const int Remains= Value%static_cast<int>(Scale);

	//四舍五入
	return FMath::Abs(Remains) > Scale / 2?Value-Remains+(Value<0?-Scale:Scale):Value-Remains;
}

FVector ABomberCharacter::GetSnappedPosition(FVector SourcePos)
{
	SourcePos.X =GetSnappedValue(SourcePos.X, 100.0f);
	SourcePos.Y = GetSnappedValue(SourcePos.Y, 100.0f);

	const FVector TempPos = FVector(SourcePos.X, SourcePos.Y, 0);
	return TempPos;
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
	//是否超出放置数量
	if (PlacedBombs.Num()>=BombLimit)
	{
		return;
	}

	if (Bomb)
	{
		//生成物的拥有者
		FActorSpawnParameters Parameters;
		Parameters.Owner = this;

		const FVector SpawnPos = GetSnappedPosition(GetActorLocation());
		ABomb* TempBomb = GetWorld()->SpawnActor<ABomb>(Bomb, SpawnPos, FRotator::ZeroRotator,Parameters);
		TempBomb->SetBlastRange(BlastRange);
		PlacedBombs.Add(TempBomb);
	}
}

void ABomberCharacter::ResetInitial(EPowerupType PowerupType)
{
	switch (PowerupType) {
		case EPowerupType::SpeedBoost:
			GetCharacterMovement()->MaxWalkSpeed = InitialMaxWalkSpeed;
			break;
		case EPowerupType::MoreBombs:
			BombLimit = InitialBombLimit;
			break;
		case EPowerupType::LongerBlast:
			BlastRange = InitialBlastRange;
			break;
		case EPowerupType::RemoteBomb:
			bHasRemote = false;
			break;
		default: ;
	}
}

