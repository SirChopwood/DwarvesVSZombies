#include "DvZ/Core/Character/CharacterCameraComponent.h"


FVector UCharacterCameraComponent::GetCursorPosAroundCharacter()
{
	float LocationX;
	float LocationY;
	FVector WorldLocation;
	FVector WorldDirection;
	float T;
	FVector Intersection;

	APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	OurPlayerController->GetMousePosition(LocationX, LocationY);
	OurPlayerController->DeprojectScreenPositionToWorld(LocationX, LocationY, WorldLocation, WorldDirection);
	FVector LineEnd = WorldLocation + (WorldDirection * static_cast<FVector>(9999.0f));
	FVector PlaneOrigen = ParentCharacter->K2_GetActorLocation();

	UKismetMathLibrary::LinePlaneIntersection_OriginNormal(WorldLocation, LineEnd, PlaneOrigen,
	                                                       FVector(0.0f, 0.0f, 0.0f), T, Intersection);
	return Intersection;
}

FVector UCharacterCameraComponent::GetTargetCameraPos()
{
	//Track towards cursor if aiming, else center on character
	FTransform T = ParentCharacter->GetTransform();
	FVector CursorPosAroundCharacter = GetCursorPosAroundCharacter();
	FVector A = T.InverseTransformPosition(CursorPosAroundCharacter);
	FVector ClampLocation = A.GetClampedToSize(0.0f, MaxAimDistance);
	FVector CursorFalseLocation = T.TransformPosition(ClampLocation);

	FVector ActorLocation = ParentCharacter->K2_GetActorLocation();
	double Dist = FVector::Distance(CursorPosAroundCharacter, ActorLocation);

	bool Index = !(IsAiming && (Dist > 200.0f));

	FVector CursorLocation = Index ? ActorLocation : CursorFalseLocation;

	//Add randomised sway
	double GameTimeInSeconds = UKismetSystemLibrary::GetGameTimeInSeconds(this);

	double X = FMath::Sin(UE_DOUBLE_PI / (180.0f) * (GameTimeInSeconds * 15.0f));
	double Y = FMath::Cos(UE_DOUBLE_PI / (180.0f) * ((GameTimeInSeconds * 15.0f) * 1.2345f));
	FVector RandomSway = FVector(X, Y, 0.0f) * 10.0f;

	return CursorLocation + RandomSway;
}

