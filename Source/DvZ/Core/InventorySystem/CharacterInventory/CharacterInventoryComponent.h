#pragma once
#include "../InventoryComponent.h"
#include "CharacterInventoryComponent.generated.h"
/** Please add a class description */
UCLASS(Blueprintable, BlueprintType)
class UCharacterInventoryComponent : public UInventoryComponent
{
	GENERATED_BODY()
public:
	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void GetCurrentHotbarItem(UObject*& Output);
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UUserWidget> InventoryWidget;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UUserWidget> CurrentTooltip;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default", Replicated)
	int32 CurrentHotbarIndex;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	int32 HotbarSize;

	//Replication logic for unreals build in multiplayer api
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
