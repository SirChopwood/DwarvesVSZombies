// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S_TooltipStat.h"
#include "UObject/Interface.h"
#include "InventoryInterface.generated.h"
/**
 * 
 */
UINTERFACE(Blueprintable)
class UInventoryInterface : public UInterface
{
	GENERATED_BODY()
};

class DVZ_API IInventoryInterface {
	GENERATED_BODY()
public:
	
	/** Please add a function description */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Tooltip")
	void GetTooltipData(UPARAM(ref) TArray<FS_TooltipStat>& PreviousStats, FText& Title, FText& Description,
	                    TArray<FS_TooltipStat>& Stats);

	/** Please add a function description */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Tooltip")
	void HideTooltip(bool& Success);

	/** Please add a function description */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Item Slots")
	void GetItemFromSlot(UObject*& Item);

	/** Please add a function description */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Item Slots")
	void SetItemToSlot(UObject* Item);

	/** Please add a function description */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Tooltip")
	void ShowTooltip(FText& Title, FText& Description, UPARAM(ref) TArray<FS_TooltipStat>& Stats);

	/** Please add a function description */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Item Slots")
	void SetDisplayQuantity(int32 Amount);

	
	
};
