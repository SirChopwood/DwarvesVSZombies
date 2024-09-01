#pragma once
#include "S_DamageOverTimeStack.generated.h"
enum class EDamageTypes : uint8;

USTRUCT(Blueprintable)
struct FS_DamageOverTimeStack
{
	GENERATED_BODY()
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Type", MakeStructureDefaultValue="NewEnumerator0"))
	TEnumAsByte<EDamageTypes> Type;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Amounts"))
	TArray<double> Amounts;

};
