#pragma once

#include "E_DamageTypes.generated.h"

UENUM(BlueprintType)
enum class EDamageTypes : uint8 {
	VE_Basic        UMETA(DisplayName="Basic"),
	VE_Flame        UMETA(DisplayName="Flame"),
	VE_Poison		UMETA(DisplayName="Poison"),
	VE_Magic		UMETA(DisplayName="Magic"),
};