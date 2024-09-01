// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "CharacterComponent.generated.h"

//class AController;
class USpringArmComponent;
class UCameraComponent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnParentControllerChangedSignature, APawn*, Pawn, AController*, OldController, AController*,NewController);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class DVZ_API UCharacterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCharacterComponent();
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Runtime")
	TObjectPtr<ACharacter> ParentCharacter;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<USpringArmComponent> SpringArm_0;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UCameraComponent> Camera_0;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UArrowComponent> DirectionArrow_0;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPossessedByLocalPlayerDispatcher);
	UPROPERTY(BlueprintAssignable,BlueprintCallable, EditDefaultsOnly, Category="Default")
	FOnPossessedByLocalPlayerDispatcher PossessedByLocalPlayer;

	UPROPERTY(BlueprintAssignable,BlueprintCallable, EditDefaultsOnly, Category="Default")
	FOnParentControllerChangedSignature ParentControllerChanged;
	
	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBeginPlayServerDispatcher);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	FBeginPlayServerDispatcher PlayServer;

protected:
	// Called when the game starts
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Begin Play"))
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
  Blueprint implementable event for when the component is beginning play, called before its owning actor's BeginPlay
  or when the component is dynamically created if the Actor has already BegunPlay.
  */
	
	

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void BeginPlayServer();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void OnPossessedByLocalPlayer();
	

	/** Please add a function description */
	

private:
	UFUNCTION(BlueprintCallable)
	void OnParentControllerChanged(APawn* Pawn, AController* OldController, AController* NewController);
		
};
