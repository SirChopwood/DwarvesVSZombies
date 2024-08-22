// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Character/DvZCharacterComponent.h"
#include "DvZItemBase.h"
#include "Components/ActorComponent.h"
#include "DvZInventoryComponent.generated.h"



UCLASS( Blueprintable )
class DVZ_API UDvZInventoryComponent : public UDvZCharacterComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDvZInventoryComponent();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void AddItemToContents(int32 Index, ADvZItemBase *Item, bool& Success);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	

		
};
