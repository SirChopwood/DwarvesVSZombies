#pragma once
#include "../InventoryComponent.h"
#include "DwarfEquipmentComponent.generated.h"
/** Please add a class description */
UCLASS(Blueprintable, BlueprintType)
class UDwarfEquipmentComponent : public UInventoryComponent
{
	GENERATED_BODY()
public:
	/** Please add a function description */
	virtual void AddItemToContents(int32 Index, UItemObject* Item, bool& Success) override;

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void RemoveItemFromContents(int32 Index, UItemObject* Item, bool& Success);
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UUserWidget> EquipmentMenu;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UUserWidget> InventoryWidget;
};
