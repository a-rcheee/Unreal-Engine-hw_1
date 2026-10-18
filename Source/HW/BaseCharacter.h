// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HWCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "BaseCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractionSignature);

class UInputAction;
class UInputMappingContext;

UCLASS()
class HW_API ABaseCharacter : public AHWCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> SprintAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> InteractAction;

	void OnSprintStarted();
	void OnSprintCompleted();
	void OnInteract();

public:	
	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnInteractionSignature OnInteraction;

	UPROPERTY(BlueprintReadOnly, Category = "Movement|Sprint")
	bool bIsSprinting = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement|Sprint")
	float WalkSpeed = 500.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement|Sprint")
	float SprintSpeed = 900.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement|Stamina")
	float MaxStamina = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement|Stamina")
	float CurrentStamina = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement|Stamina")
	float StaminaDrainRate = 25.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement|Stamina")
	float StaminaRegenRate = 15.0f;

private:
	bool bWantsToSprint = false;
	void StopSprinting();
};
