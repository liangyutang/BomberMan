// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "BomberPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABomberPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

protected:
	UPROPERTY(EditAnywhere)
	APawn* NowPawn;
	

protected:

	virtual void BeginPlay() override;

	void MoveVertical(const FInputActionValue& InputValue);

	void MoveHorizontal(const FInputActionValue& InputValue);

private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Context", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> IMC_Move;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Context", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> IMC_Move2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Context", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_MoveVertical;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Context", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> IA_MoveHorizontal;
};
