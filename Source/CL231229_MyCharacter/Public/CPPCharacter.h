// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"

#include "CPPCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

UCLASS()
class CL231229_MYCHARACTER_API ACPPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPPCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<USpringArmComponent> CPPSpringArm;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	TObjectPtr<UCameraComponent> CPPCamera;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inputs")
	TObjectPtr<UInputAction> IA_Look;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inputs")
	TObjectPtr<UInputAction> IA_Move;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inputs")
	TObjectPtr<UInputAction> IA_Jump;

public:
	void Look(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);
};
