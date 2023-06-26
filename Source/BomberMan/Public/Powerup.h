// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BomberMan/BomberManGameModeBase.h"
#include "GameFramework/Actor.h"
#include "Powerup.generated.h"

UCLASS()
class BOMBERMAN_API APowerup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerup();

protected:

	UPROPERTY(VisibleAnywhere,Category="Component")
	class UBoxComponent* BoxCollision;

	//´æ·ÅÌùÍ¼
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UBillboardComponent* Billboard;

	//ÌùÍ¼Êý×é
	UPROPERTY(EditAnywhere,Category="Component")
	TArray<UTexture2D*> Sprites;

	EPowerupType PowerupType;

	UPROPERTY(EditAnywhere,Category="Powerup")
	int SpeedBoost = 50;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
