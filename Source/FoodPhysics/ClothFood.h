// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlexActor.h"
#include "Particles/Emitter.h"
#include "ClothFood.generated.h"

/**
 * 
 */
UCLASS()
class FOODPHYSICS_API AClothFood : public AFlexActor
{
	GENERATED_BODY()
	
public:
	
	AClothFood();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	AEmitter* Emitter;
	
};
