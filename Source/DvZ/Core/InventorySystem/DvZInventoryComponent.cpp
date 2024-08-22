// Fill out your copyright notice in the Description page of Project Settings.


#include "DvZInventoryComponent.h"

// Sets default values for this component's properties
UDvZInventoryComponent::UDvZInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UDvZInventoryComponent::AddItemToContents(int32 Index, ADvZItemBase *Item, bool& Success)
{

}


// Called when the game starts
void UDvZInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDvZInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

