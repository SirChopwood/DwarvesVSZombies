#pragma once

#include "../Character/CharacterStatComponent.h"
#include "HealthComponent.generated.h"
struct FS_DamageOverTimeStack;
class UDwarfArmourComponent;
enum class EHealthStates : uint8;
enum class EDamageTypes : uint8;
/** Please add a class description */
UCLASS(Blueprintable, BlueprintType)
class UHealthComponent : public UCharacterStatComponent
{
	GENERATED_BODY()
public:
	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void AddDamageOverTime(double Value, TEnumAsByte<EDamageTypes> IgnoresArmour, double DamagePerSecond, TArray<double> NewDoTStacks);

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void TickDamageOverTime();
public:
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default", Replicated)
	TEnumAsByte<EHealthStates> HealthState;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UUserWidget> StatBar;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UDwarfArmourComponent> ArmourComponent;

	/* Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TArray<FS_DamageOverTimeStack> DoTStacks;
	
	
	//Replication logic for unreals build in multiplayer api
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
