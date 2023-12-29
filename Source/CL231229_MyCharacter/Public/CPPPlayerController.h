// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPPPlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class CL231229_MYCHARACTER_API ACPPPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Mapping")
	TObjectPtr<UInputMappingContext> DefaultIMC;
};
