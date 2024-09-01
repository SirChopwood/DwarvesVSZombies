// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "CharacterComponent.generated.h"


class USpringArmComponent;
class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class DVZ_API UCharacterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Runtime")
	TObjectPtr<ACharacter> ACharacterBase;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<USpringArmComponent> SpringArm_0;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UCameraComponent> Camera_0;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UArrowComponent> DirectionArrow_0;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNewEventDispatcher);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	FNewEventDispatcher NewEventDispatcher;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNewEventDispatcher_0);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	FNewEventDispatcher_0 NewEventDispatcher_0;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	//virtual void BeginPlayServer() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
