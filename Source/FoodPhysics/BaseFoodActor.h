// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "FlexComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "BaseFoodActor.generated.h"

UCLASS()
class FOODPHYSICS_API ABaseFoodActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseFoodActor();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	USceneComponent* SceneRoot;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UBoxComponent* CollisionMesh;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UFlexComponent* FlexMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void SpawnObject(FVector Loc, FRotator Rot);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
