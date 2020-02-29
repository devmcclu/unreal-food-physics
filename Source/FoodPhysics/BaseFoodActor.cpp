// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseFoodActor.h"
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)


// Sets default values
ABaseFoodActor::ABaseFoodActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SceneRoot->SetupAttachment(RootComponent);

	FlexMesh = CreateDefaultSubobject<UFlexComponent>(TEXT("Flex"));
	FlexMesh->SetupAttachment(SceneRoot);

	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	CollisionMesh->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void ABaseFoodActor::BeginPlay()
{
	Super::BeginPlay();

    CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &ABaseFoodActor::OnOverlapBegin);
	
}

// Called every frame
void ABaseFoodActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseFoodActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	print(TEXT("Help me"));
	FRotator objectRotation = FRotator();
	SpawnObject(GetActorLocation(), objectRotation);
}

void ABaseFoodActor::SpawnObject(FVector Loc, FRotator Rot)
{
	FActorSpawnParameters SpawnParams;
	AActor* SpawnedActorRef = GetWorld()->SpawnActor<AActor>(ActorToSpawn, Loc, Rot, SpawnParams);
}

