#pragma once

#include "CharacterComponent.h"
#include "CharacterStatComponent.generated.h"
/** Please add a class description */
UCLASS(Blueprintable, BlueprintType)
class UCharacterStatComponent : public UCharacterComponent
{
	GENERATED_BODY()
public:
	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void OnRep_CurrentValue();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void OnRep_MaxValue();

	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void OnRep_MinValue();
public:
	/** Please add a variable description */
	//static_assert(false, "You will need to add DOREPLIFETIME(UBP_DvZCharacterStatComponent, CurrentValue) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", ReplicatedUsing="OnRep_CurrentValue")
	double CurrentValue;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", ReplicatedUsing="OnRep_MaxValue")
	double MaxValue;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default", ReplicatedUsing="OnRep_MinValue")
	double MinValue;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnValueUpdated);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	FOnValueUpdated OnValueUpdated;

	//Replication logic for unreals build in multiplayer api
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
