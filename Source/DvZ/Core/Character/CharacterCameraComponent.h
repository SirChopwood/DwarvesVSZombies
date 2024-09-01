#pragma once

#include "CharacterComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "CharacterCameraComponent.generated.h"


/** Please add a class description */
UCLASS(Blueprintable, BlueprintType)
class UCharacterCameraComponent : public UCharacterComponent
{
	GENERATED_BODY()
public:

	
	/** Please add a function description */
	UFUNCTION(BlueprintPure)
	FVector GetCursorPosAroundCharacter();

	/** Please add a function description */
	UFUNCTION(BlueprintPure)
	FVector GetTargetCameraPos();


	
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Runtime")
	FVector TargetCameraPosition;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	bool ShowDebug;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Runtime")
	TObjectPtr<ACharacter> ParentCharacter;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double VelocityPredictionBlendSpeed;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<USpringArmComponent> SpringArm;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UCameraComponent> Camera;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Runtime")
	bool ShouldTick;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double TargetZoom;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double MinZoom;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double MaxZoom;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double ZoomBlendSpeed;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double PredictionDistance;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Default")
	TObjectPtr<UArrowComponent> DirectionArrow;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double MaxAimRegion;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double MinAimRegion;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double MaxAimDistance;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Runtime")
	bool IsAiming;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Runtime")
	FRotator TargetCameraRotation;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	double CameraRotationSpeed;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Config")
	bool CameraRotationSmoothing;
};
