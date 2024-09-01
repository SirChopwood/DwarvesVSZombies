#pragma once

#include "../Character/CharacterComponent.h"
#include "Net/UnrealNetwork.h"
#include "CombatModeComponent.generated.h"
/** Please add a class description */
UCLASS(Blueprintable, BlueprintType)
class UCombatModeComponent : public UCharacterComponent
{
	GENERATED_BODY()
public:
	/** Please add a function description */
	UFUNCTION(BlueprintCallable)
	void OnRep_IsCombatModeActive();
	
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Runtime", ReplicatedUsing="OnRep_IsCombatModeActive")
	bool IsCombatModeActive;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Runtime")
	FTimerHandle CombatModeCooldownTimer;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	float CombatModeCooldown;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatModeChanged, bool, IsCombatModeActive);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	FOnCombatModeChanged OnCombatModeChanged;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double PassiveModeWalkSpeed;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double CombatModeWalkSpeed;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Runtime")
	FTimerHandle CombatModeDirectionTickClientTimer;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	FRotator PassiveModeRotationRate;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	FRotator CombatModeRotationRate;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Runtime")
	TObjectPtr<UUserWidget> CombatModeWidget;

	//Replication logic for unreals build in multiplayer api
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
