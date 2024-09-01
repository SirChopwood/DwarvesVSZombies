#pragma once

#include "Components/Widget.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UCharacterInventoryComponent;
class UCharacterCameraComponent;
class UHealthComponent;
class UCombatModeComponent;
/** Please add a class description */
UCLASS(Blueprintable, BlueprintType)
class ACharacterBase : public ACharacter
{
	GENERATED_BODY()
public:
	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void UpdateMovementSpeed();
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TObjectPtr<UCharacterInventoryComponent> BP_DvZCharacterInventoryComponent;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TObjectPtr<UCombatModeComponent> BP_DvZCombatModeComponent;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TObjectPtr<UHealthComponent> BP_DvZHealthComponent;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Default")
	TObjectPtr<UCharacterCameraComponent> BP_DvZCharacterCameraComponent;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UUserWidget> HotbarWidget;
};
