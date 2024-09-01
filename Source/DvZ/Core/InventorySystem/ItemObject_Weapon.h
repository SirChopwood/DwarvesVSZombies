#pragma once

#include "ItemObject.h"
#include "ItemObject_Weapon.generated.h"

enum class EWeaponType : uint8;
/** Please add a class description */
UCLASS(Blueprintable, BlueprintType)
class UItemObject_Weapon : public UItemObject
{
	GENERATED_BODY()
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	TObjectPtr<UStaticMesh> WeaponMesh;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	TEnumAsByte<EWeaponType> WeaponType;
};
