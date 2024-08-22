// Fill out your copyright notice in the Description page of Project Settings.


#include "DvZItemBase.h"

// Sets default values
ADvZItemBase::ADvZItemBase(): Quantity(1), MaxStackSize(1)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADvZItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADvZItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// The replication logic for the variable Quantity making it replicated in all clients connected to the server
void ADvZItemBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Add properties to replicated for the ADvZItemBase class
	DOREPLIFETIME(ADvZItemBase, Quantity);
}

