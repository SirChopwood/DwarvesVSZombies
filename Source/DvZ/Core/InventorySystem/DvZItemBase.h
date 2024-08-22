// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "DvZItemBase.generated.h"

UCLASS(Blueprintable)
class DVZ_API ADvZItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADvZItemBase();

	// The name of the item
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FText Name;

	// The description of the item
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", meta = (MultiLine = "true"))
	FText Description;

	// Pointer to a 2d texture that contains the icon of the object
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", meta = (MultiLine = "true"))
	TObjectPtr<UTexture2D> Icon;

	// Honestly not sure what it does yet, and it is not yet implemented in anything but seems to be tracking the durability of an item
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDurabilityUpdated, int32, NewDurability);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category = "Default")
	FOnDurabilityUpdated OnDurabilityUpdated;

	// The quantity of the item, is replicated on the network so everyone can see the amount
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", Replicated, meta = (UIMin = "1", ClampMin = "1"))
	int32 Quantity;

	// The maximum size of an item stack
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", meta = (UIMin = "1", ClampMin = "1"))
	int32 MaxStackSize;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
