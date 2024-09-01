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
	
	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void OnRep_InventoryContents();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	virtual void RemoveItemFromContents(int32 Index, UItemObject* Item, bool& Success);

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void SwapItemsBetweenInventories(UInventoryComponent* SourceComponent, int32 SourceIndex,
	                                 UInventoryComponent* TargetComponent, int32 TargetIndex, bool& Success,
	                                 UItemObject* SourceItem, UItemObject* TargetItem);

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void DebugPrintContents(UInventoryComponent* TargetComponent);

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void SplitItemStackFromContents(UInventoryComponent* SourceComponent, int32 SourceIndex,
	                                UInventoryComponent* TargetComponent, int32 TargetIndex, bool& Success,
	                                UItemObject* SourceItem);

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void MergeItemStacksToContents(UItemObject* Item, int32 Index, bool& Success);

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(UIMin="1", ClampMin="1"))
	int32 InventorySize;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default", ReplicatedUsing="OnRep_InventoryContents")
	TArray<UItemObject*> InventoryContents;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	double SplitRatio;

	//Replication logic for unreals build in multiplayer api
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	

		
};
