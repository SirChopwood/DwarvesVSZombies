#include "CharacterInventoryComponent.h"

void UCharacterInventoryComponent::GetCurrentHotbarItem(UObject*& Output)
{
}

void UCharacterInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCharacterInventoryComponent, CurrentHotbarIndex)
}
