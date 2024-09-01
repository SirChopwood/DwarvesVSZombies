﻿#pragma once


#include "CoreMinimal.h"
#include "S_EnchantmentTiers.generated.h"
class UPDA_Enchantments;

USTRUCT(Blueprintable)
struct FS_EnchantmentTiers 
{
	GENERATED_BODY()
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Enchantment", MakeStructureDefaultValue="None"))
	TObjectPtr<UPDA_Enchantments> Enchantment;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Tier", MakeStructureDefaultValue="0"))
	int32 Tier = 1;
};