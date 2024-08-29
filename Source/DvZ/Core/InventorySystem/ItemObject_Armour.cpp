// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemObject_Armour.h"

UItemObject_Armour::UItemObject_Armour(): MaxDurability(1), CurrentDurability(1), Slot(), ItemBaseArmour(1)
{
}

void UItemObject_Armour::GetArmourValues(double& BaseArmour, double& ArmourPostEnchants, double& ArmourPostDurability)
{
	UPDA_Enchantments* Query = NewObject<UDA_Enchantment_Reinforced>();
	bool Found;
	int32 Tier;
	double PrimaryValue; 
	double SecondaryValue;
	double TertiaryValue;
	UObject* Enchantment;
	GetEnchantment( Query, Found, Enchantment,Tier, PrimaryValue, SecondaryValue,  TertiaryValue );
	BaseArmour = static_cast<double>(ItemBaseArmour);
	ArmourPostEnchants=((PrimaryValue/100.0+1.0)*BaseArmour);
	ArmourPostDurability=ArmourPostEnchants*(static_cast<double>( CurrentDurability )/static_cast<double>( MaxDurability ));
	
	
}

void UItemObject_Armour::GetTooltipData_Implementation(TArray<FS_TooltipStat>& PreviousStats, FText& Title,
	FText& Description, TArray<FS_TooltipStat>& Stats)
{
	
	//Gets the Slot Stat
	FText SlotText = FText::FromString(UEnum::GetValueAsString(Slot));
	const FLinearColor Cyan = FColor::FromHex("00FFFFCC");
	PreviousStats.Append({{SlotText, Cyan}});
	
	//Gets the tooltip information of the item from the parent function
	UItemObject::GetTooltipData_Implementation(PreviousStats, ItemName, ItemDescription, Stats);

	//Gets the Durability Stat
	FText DurabilityStatText = FText::FromString("Durability: "+ FString::FromInt(CurrentDurability) +"/" + FString::FromInt(MaxDurability));
	double Alpha = static_cast<double>( CurrentDurability )/static_cast<double>( MaxDurability );
	const FLinearColor Red = FColor::FromHex("FF0000CC");
	const FLinearColor Lime = FColor::FromHex("00FF00CC");
	const FLinearColor LerpColour = UKismetMathLibrary::LinearColorLerp(Red,Lime,Alpha);
	Stats.Append({{DurabilityStatText, LerpColour}});

	
}

void UItemObject_Armour::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Add properties to replicated for the UItemObject_Armour class
	DOREPLIFETIME(UItemObject_Armour, CurrentDurability);
}
