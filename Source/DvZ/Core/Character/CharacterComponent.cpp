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




// Called every frame
void UCharacterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UCharacterComponent::BeginPlay()
{
	UActorComponent::BeginPlay();
	
	//Subscribing to the events
	ParentControllerChanged.AddDynamic(this,&UCharacterComponent::OnParentControllerChanged);
	PossessedByLocalPlayer.AddDynamic(this, &UCharacterComponent::OnPossessedByLocalPlayer);
	PlayServer.AddDynamic(this, &UCharacterComponent::BeginPlayServer);
	
	TObjectPtr<AActor> OwnerActor = GetOwner();
	ParentCharacter = Cast<ACharacter>(OwnerActor);
	TObjectPtr<AController> Controller = ParentCharacter->GetController();
	if(IsValid(Controller))
	{
		TObjectPtr<AController> OldController;
		//broadcasting the event ParentControllerChanged
		ParentControllerChanged.Broadcast(ParentCharacter,OldController,Controller);
	}
	if(OwnerActor->HasAuthority())
	{
		PlayServer.Broadcast();
	}
	
	
}

void UCharacterComponent::BeginPlayServer()
{
}

void UCharacterComponent::OnPossessedByLocalPlayer()
{
}

void UCharacterComponent::OnParentControllerChanged(APawn* Pawn, AController* OldController, AController* NewController)
{
	
	
	if(Pawn->IsLocallyControlled())
	{
		PossessedByLocalPlayer.Broadcast();
	}
}

