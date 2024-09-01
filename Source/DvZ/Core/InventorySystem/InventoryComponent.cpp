// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UInventoryComponent::AddItemToContents(int32 Index, UItemObject *Item, bool& Success)
{

}

void UInventoryComponent::OnRep_InventoryContents()
{
}

void UInventoryComponent::RemoveItemFromContents(int32 Index, UItemObject* Item, bool& Success)
{
}

void UInventoryComponent::SwapItemsBetweenInventories(UInventoryComponent* SourceComponent, int32 SourceIndex,
                                                      UInventoryComponent* TargetComponent, int32 TargetIndex, bool& Success, UItemObject* SourceItem,
                                                      UItemObject* TargetItem)
{
}

void UInventoryComponent::DebugPrintContents(UInventoryComponent* TargetComponent)
{
}

void UInventoryComponent::SplitItemStackFromContents(UInventoryComponent* SourceComponent, int32 SourceIndex,
	UInventoryComponent* TargetComponent, int32 TargetIndex, bool& Success, UItemObject* SourceItem)
{
}

void UInventoryComponent::MergeItemStacksToContents(UItemObject* Item, int32 Index, bool& Success)
{
}


void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UInventoryComponent, InventoryContents)
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

