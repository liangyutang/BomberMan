// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomb.generated.h"

UCLASS()
class BOMBERMAN_API ABomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomb();

	FTimerHandle TimerHandle_Detonate;

	UPROPERTY(EditAnywhere,Category="FX")
	float DetonateDelay = 1.0f;
protected:

	UPROPERTY(VisibleAnywhere,Category="Component")
	class UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UStaticMeshComponent* BomberSM;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UParticleSystemComponent* SparkPar;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void Detonate();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
