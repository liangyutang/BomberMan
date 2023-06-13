// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "BomberCharacter.generated.h"

UCLASS()
class BOMBERMAN_API ABomberCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABomberCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveVertical(const FInputActionValue& InputValue);

	void MoveHorizontal(const FInputActionValue& InputValue);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Context",meta=(AllowPrivateAccess="true"))
	TObjectPtr<class UInputMappingContext> IMC_Move;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Context", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_MoveVertical;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Context", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_MoveHorizontal;
};
