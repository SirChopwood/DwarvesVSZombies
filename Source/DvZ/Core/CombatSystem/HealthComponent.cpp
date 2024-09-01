#include "HealthComponent.h"

#include "Net/UnrealNetwork.h"

void UHealthComponent::AddDamageOverTime(double Value, TEnumAsByte<EDamageTypes> IgnoresArmour, double DamagePerSecond,
                                         TArray<double> NewDoTStacks)
{
}

void UHealthComponent::TickDamageOverTime()
{
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(UHealthComponent, HealthState);
}
