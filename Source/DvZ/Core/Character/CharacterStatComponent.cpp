#include "CharacterStatComponent.h"

#include "Net/UnrealNetwork.h"

void UCharacterStatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCharacterStatComponent, MinValue);
	DOREPLIFETIME(UCharacterStatComponent, MaxValue);
}
