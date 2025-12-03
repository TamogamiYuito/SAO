// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/VRActor.h"
#include "Interface/InteractInterface.h"
#include "VRGrabbaleActor.generated.h"


class UBoxComponent;

UENUM(BlueprintType)
enum class EGrabType : uint8
{
	Free,
	Snap,
	None
};

UCLASS()
class SAO_API AVRGrabbaleActor : public AVRActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	AVRGrabbaleActor();


protected:

	virtual void OnGrab(USkeletalMeshComponent* InComponent, const FVector& GrabLocation);
	virtual void OnRelease(USkeletalMeshComponent* InComponent);


#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent> GrabRegion;

#pragma endregion


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Setup")
	EGrabType GrabType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	bool bIsHeld;
	

private:
	USkeletalMeshComponent* GrabbedBySkeletalMesh;
};
