// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "InventoryInterface.h"
//#include "PDA_Enchantments.h"
#include "S_EnchantmentTiers.h"
#include "ItemObject.generated.h"

UCLASS(Blueprintable)
class DVZ_API UItemObject : public UObject, public IInventoryInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UItemObject();
	/** Please add a function description */
	UFUNCTION(BlueprintCallable, Category="Default")
	void GetEnchantment(UPDA_Enchantments* Query, bool& Found, UObject*& Enchantment, int32& Tier, double& PrimaryValue, double& SecondaryValue, double& TertiaryValue);

	// The name of the item
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", DisplayName="Name")
	FText ItemName;

	// The description of the item
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", DisplayName="Description", meta = (MultiLine = "true"))
	FText ItemDescription;
	
	// Pointer to a 2d texture that contains the icon of the object
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", meta = (MultiLine = "true"))
	TObjectPtr<UTexture2D> Icon;

	// Event dispatcher for durability updates
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDurabilityUpdated, int32, NewDurability);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category = "Default")
	FOnDurabilityUpdated OnDurabilityUpdated;

	// The quantity of the item, is replicated on the network so everyone can see the amount
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", Replicated, meta = (UIMin = "1", ClampMin = "1"))
	int32 Quantity;

	// The maximum size of an item stack
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", meta = (UIMin = "1", ClampMin = "1"))
	int32 MaxStackSize;

	UFUNCTION(BlueprintCallable, Category="Tooltip")
	virtual void GetTooltipData_Implementation(UPARAM(ref) TArray<FS_TooltipStat> PreviousStats, FText Title, FText Description, TArray<FS_TooltipStat>& Stats);

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	TArray<FS_EnchantmentTiers> Enchantments;

protected:
	// Called when the game starts or when spawned
	

public:	
	// Called every frame
	

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
