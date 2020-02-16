// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/StaticMeshComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKSUSPENSION_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category="Tank Setup")
	void Setup(UStaticMeshComponent* RightTrack, UStaticMeshComponent* LeftTrack, UStaticMeshComponent* Body);

	UFUNCTION(BlueprintCallable, Category="Tank Movement")
	void Move(float Throttle);

	UFUNCTION(BlueprintCallable, Category="Tank Movement")
	void Turn(float Throttle);

private:

	UStaticMeshComponent* RightTrack = nullptr;
	UStaticMeshComponent* LeftTrack = nullptr;
	UStaticMeshComponent* Body = nullptr;

	UPROPERTY(EditAnywhere, Category="Tank Setup")
	float Acceleration = 1000;
};
