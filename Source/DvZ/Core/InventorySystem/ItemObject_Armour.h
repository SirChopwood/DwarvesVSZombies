// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemObject.h"
#include "E_EquipmentSlots.h"
#include "ItemObject_Armour.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class DVZ_API UItemObject_Armour : public UItemObject
{
	GENERATED_BODY()
public:
	/* Please add a function description */
	//virtual void GetTooltipData_Implementation(UPARAM(ref) TArray<FS_TooltipStat>& PreviousStats, FText Title, FText Description, TArray<FS_TooltipStat>& Stats) override;
	UItemObject_Armour();
	/* Please add a function description */
	UFUNCTION(BlueprintCallable, Category="Default")
	void GetArmourValues(double& BaseArmour, double& ArmourPostEnchants, double& ArmourPostDurability);
	
	/* Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(UIMin="1", ClampMin="1"))
	int32 MaxDurability;

	/* Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", meta=(UIMin="1", ClampMin="1"))
	int32 CurrentDurability;

	/* Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	TEnumAsByte<E_EquipmentSlots> Slot;

	/* Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", DisplayName="BaseArmour")
	double ItemBaseArmour;

	/* Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	TObjectPtr<USkeletalMesh> ArmourMesh;

	
};
