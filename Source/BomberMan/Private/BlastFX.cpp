// Fill out your copyright notice in the Description page of Project Settings.



#include "BlastFX.h"

// Sets default values
ABlastFX::ABlastFX()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComp->SetupAttachment(RootComponent);

	BlastFxSM = CreateDefaultSubobject<UStaticMeshComponent>("BlastFxSM");
	BlastFxSM->SetupAttachment(RootComp);

}

// Called when the game starts or when spawned
void ABlastFX::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlastFX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlastFX::SetupBlast(FVector InitPos, FVector LastPos)
{
	//获取长度
	float Stretch= FVector::Distance(InitPos, LastPos) / 100;

	FVector Scale = GetActorScale3D();

	if (InitPos.X==LastPos.X)
	{
		//垂直方向
		Scale.X = Stretch;
	}else if (InitPos.Y == LastPos.Y)
	{
		//水平方向
		Scale.Y = Stretch;
		//旋转
		SetActorRotation(FRotator(0, 0, 90));
	}
	SetActorScale3D(Scale);
}

