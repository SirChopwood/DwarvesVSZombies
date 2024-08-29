#pragma once
#include "PDA_Enchantments.h"
#include "DA_Enchantment_Lightweight.generated.h"

UCLASS(Blueprintable)
class UDA_Enchantment_Lightweight : public UPDA_Enchantments
{
	GENERATED_BODY()

public:
	FText Name = FText::FromString("Lightweight");

	/** Please add a variable description */
	int32 MaxTiers = 3;

	/* Please add a variable description */
	TArray<double> PrimaryValue{3.0, 6.0, 8.0};
};
