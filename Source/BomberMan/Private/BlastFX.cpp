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

	GetWorldTimerManager().SetTimer(TimerHandle_Destroy, this, &ABlastFX::DelayDestroy, 1.0f, false);
}

void ABlastFX::DelayDestroy()
{
	Destroy();
}

// Called every frame
void ABlastFX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlastFX::SetupBlast(FVector InitPos, FVector LastPos)
{
	//获取长度
	const float Stretch= FVector::Distance(InitPos, LastPos) / 100;

	FVector Scale = GetActorScale3D();
	//设置长度
	Scale.X = Stretch;
	SetActorScale3D(Scale);
}

