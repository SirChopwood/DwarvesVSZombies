#pragma once

#include "CoreMinimal.h"
#include "E_WeaponType.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8 {
	VE_Melee        UMETA(DisplayName="Melee"),
	VE_Ranged       UMETA(DisplayName="Ranged"),
	VE_Special		UMETA(DisplayName="Special"),
};