#pragma once
#include "../Character/CharacterStatComponent.h"

/** Please add a class description */
UCLASS(Blueprintable, BlueprintType)
class UDwarfArmourComponent : public UCharacterStatComponent
{
	GENERATED_BODY()
public:
	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void CalculateArmourValue(double NewBaseValue, double NewCurrentValue);
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UUserWidget> StatBar;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UBP_DwarfEquipmentComponent_C> EquipmentComponent;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	double BaseValue;
};
