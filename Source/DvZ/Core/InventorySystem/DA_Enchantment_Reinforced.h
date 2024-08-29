#pragma once
#include "PDA_Enchantments.h"
#include "DA_Enchantment_Reinforced.generated.h"

UCLASS(Blueprintable)
class UDA_Enchantment_Reinforced : public UPDA_Enchantments
{
	GENERATED_BODY()

public:
	FText Name = FText::FromString("Reinforced");

	/** Please add a variable description */
	int32 MaxTiers = 5;

	/* Please add a variable description */
	TArray<double> PrimaryValue{10.0, 20.0, 30.0, 40.0, 50.0};
};
