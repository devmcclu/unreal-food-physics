// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlexActor.h"
#include "GameFramework/Actor.h"
#include "BaseFood.generated.h"

/**
 * 
 */
UCLASS()
class FOODPHYSICS_API ABaseFood : public AFlexActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseFood();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
};