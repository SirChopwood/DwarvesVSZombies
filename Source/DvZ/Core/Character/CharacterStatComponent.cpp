#include "CharacterStatComponent.h"

#include "Net/UnrealNetwork.h"

void UCharacterStatComponent::OnRep_CurrentValue()
{
}

void UCharacterStatComponent::OnRep_MaxValue()
{
}

void UCharacterStatComponent::OnRep_MinValue()
{
}

void UCharacterStatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCharacterStatComponent, CurrentValue);
	DOREPLIFETIME(UCharacterStatComponent, MinValue);
	DOREPLIFETIME(UCharacterStatComponent, MaxValue);
}
