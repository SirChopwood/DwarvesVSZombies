// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemObject.h"

// Sets default values
UItemObject::UItemObject(): Quantity(1), MaxStackSize(1)
{
	
}

void UItemObject::GetEnchantment(UPDA_Enchantments* Query, bool& Found, UObject*& Enchantment, int32& Tier,
	double& PrimaryValue, double& SecondaryValue, double& TertiaryValue)
{
}

void UItemObject::GetTooltipData_Implementation(UPARAM(ref) TArray<FS_TooltipStat>& PreviousStats, FText Title, FText Description, TArray<FS_TooltipStat>& Stats)
{
	FString TooltipText;
}

// The replication logic for the variable Quantity making it replicated in all clients connected to the server
void UItemObject::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Add properties to replicated for the UItemObject class
	DOREPLIFETIME(UItemObject, Quantity);
}

