// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemObject_Armour.h"

UItemObject_Armour::UItemObject_Armour(): MaxDurability(1), CurrentDurability(1), Slot(), ItemBaseArmour(1)
{
}

void UItemObject_Armour::GetArmourValues(double& BaseArmour, double& ArmourPostEnchants, double& ArmourPostDurability)
{
}

void UItemObject_Armour::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Add properties to replicated for the UItemObject_Armour class
	DOREPLIFETIME(UItemObject_Armour, CurrentDurability);
}
