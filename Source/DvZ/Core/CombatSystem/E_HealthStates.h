#pragma once

#include "E_HealthStates.generated.h"

UENUM(BlueprintType)
enum class EHealthStates : uint8 {
	VE_Healthy      UMETA(DisplayName="Healthy"),
	VE_Injured      UMETA(DisplayName="Injured"),
	VE_Dead			UMETA(DisplayName="Dead"),
};