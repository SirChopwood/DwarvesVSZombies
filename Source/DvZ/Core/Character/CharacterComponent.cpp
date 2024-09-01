// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterComponent.h"

// Sets default values for this component's properties
UCharacterComponent::UCharacterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharacterComponent::BeginPlay()
{
	Super::BeginPlay();

	TObjectPtr<AActor> OwnerActor = GetOwner();
	Cast<ACharacter>(OwnerActor);

	// ...
	
}

void UCharacterComponent::BeginPlayServer()
{
	
}


// Called every frame
void UCharacterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

