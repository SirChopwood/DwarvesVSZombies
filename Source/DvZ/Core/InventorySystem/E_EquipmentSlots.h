#pragma once

#include "CoreMinimal.h"
#include "E_EquipmentSlots.generated.h"

UENUM(BlueprintType)
enum class EEquipmentSlots : uint8 {
	VE_Head         UMETA(DisplayName="Head"),
	VE_Chest        UMETA(DisplayName="Chest"),
	VE_Legs			UMETA(DisplayName="Legs"),
	VE_Feet			UMETA(DisplayName="Feet"),
};