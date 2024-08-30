#pragma once

#include "E_WeaponType.h"
#include "ItemObject.h"
#include "ItemObject_Weapon.generated.h"

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
	TEnumAsByte<E_WeaponType> WeaponType;
};
