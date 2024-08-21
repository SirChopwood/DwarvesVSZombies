// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "DvZItemBase.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class DVZ_API ADvZItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADvZItemBase();

	/** Please add a variable description */ 
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<USceneComponent> DefaultSceneRoot; 

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FText Name;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", meta = (MultiLine = "true"))
	FText Description;

	/** Please add a variable description */ 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", meta = (MultiLine = "true"))
	TObjectPtr<UTexture2D> Icon;

	/** Please add a variable description */ 
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDurabilityUpdated, int32, NewDurability);
	UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category = "Default")
	FOnDurabilityUpdated OnDurabilityUpdated;

	/** Please add a variable description */
	//static_assert(false, "You will need to add DOREPLIFETIME(ABP_DvZItemBase, Quantity) to GetLifetimeReplicatedProps");
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default", Replicated, meta = (UIMin = "1", ClampMin = "1"))
	int32 Quantity;

	/** Please add a variable description */
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
