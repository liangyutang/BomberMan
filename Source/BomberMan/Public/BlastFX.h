// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlastFX.generated.h"

UCLASS()
class BOMBERMAN_API ABlastFX : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlastFX();



protected:

	UPROPERTY(VisibleAnywhere,Category="Component")
	UStaticMeshComponent* BlastFxSM;
7
	UPROPERTY(VisibleAnywhere, Category = "Component")
	USceneComponent* RootComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetupBlast(FVector InitPos, FVector LastPos);

};
