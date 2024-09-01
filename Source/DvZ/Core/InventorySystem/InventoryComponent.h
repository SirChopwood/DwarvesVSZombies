// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Character/CharacterComponent.h"
#include "ItemObject.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"



UCLASS( Blueprintable )
class UInventoryComponent : public UCharacterComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	virtual void AddItemToContents(int32 Index, UItemObject *Item, bool& Success);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	

		
};
