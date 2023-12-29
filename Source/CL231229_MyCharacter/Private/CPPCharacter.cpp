// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACPPCharacter::ACPPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CPPSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Character Spring Arm"));
	CPPSpringArm->SetupAttachment(RootComponent);
	CPPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Character Camera"));
	CPPCamera->SetupAttachment(CPPSpringArm);
	
	GetMesh()->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));
}

// Called when the game starts or when spawned
void ACPPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UEIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (UEIC)
	{
		UEIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ACPPCharacter::Look);
		UEIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ACPPCharacter::Move);
		UEIC->BindAction(IA_Jump, ETriggerEvent::Completed, this, &ACPPCharacter::Jump);
	}
}

void ACPPCharacter::Look(const FInputActionValue& Value)
{
	FVector2D Direction = Value.Get<FVector2D>();

	AddControllerYawInput(Direction.X);
	AddControllerPitchInput(Direction.Y);
}

void ACPPCharacter::Move(const FInputActionValue& Value)
{
	FVector2D Direction = Value.Get<FVector2D>();

	FRotator CameraRotation = GetControlRotation();
	FRotator RotateDirection = FRotator(0, CameraRotation.Yaw, 0);

	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(RotateDirection);
	FVector RightVector = UKismetMathLibrary::GetRightVector(RotateDirection);

	AddMovementInput(ForwardVector, Direction.Y);
	AddMovementInput(RightVector, Direction.X);
}

