#include "CombatModeComponent.h"


void UCombatModeComponent::OnRep_IsCombatModeActive()
{
}

void UCombatModeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCombatModeComponent, IsCombatModeActive);
}
