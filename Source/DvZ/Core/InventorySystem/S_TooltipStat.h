#pragma once
#include "CoreMinimal.h"
#include "Styling/CoreStyle.h"
#include "S_TooltipStat.generated.h"
/** Please add a struct description */
USTRUCT(BlueprintType)
struct DVZ_API FS_TooltipStat
{
	GENERATED_BODY()
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Text"))
	FText Text;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Colour"))
	FLinearColor Colour = FLinearColor::Black;
};
