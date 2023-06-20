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

