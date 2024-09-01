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
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	bool IsCombatModeActive;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	FTimerHandle CombatModeCooldownTimer;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	float CombatModeCooldown;

	/** Please add a variable description */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatModeChanged, bool, IsCombatModeActive);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category="Default")
	FOnCombatModeChanged OnCombatModeChanged;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	double PassiveModeWalkSpeed;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	double CombatModeWalkSpeed;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default", Replicated)
	FVector TargetPos;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	FTimerHandle CombatModeDirectionTickServerTimer;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	FTimerHandle CombatModeDirectionTickClientTimer;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	FRotator PassiveModeRotationRate;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Default")
	FRotator CombatModeRotationRate;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UUserWidget> CombatModeWidget ;

	//Replication logic for unreals build in multiplayer api
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
