// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BreakableBlock.generated.h"

UCLASS()
class BOMBERMAN_API ABreakableBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABreakableBlock();

protected:

	UPROPERTY(VisibleAnywhere,Category="Breakable Block")
	UStaticMeshComponent* BreakableBlock;

	UPROPERTY(EditAnywhere,Category="Explosion")
	UParticleSystem* Explosion;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnDestroy();
};
