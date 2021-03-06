// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseFood.h"
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values
ABaseFood::ABaseFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	CollisionMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseFood::BeginPlay()
{
	Super::BeginPlay();

	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &ABaseFood::OnOverlapBegin);
}

// Called every frame
void ABaseFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseFood::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	print(TEXT("Help me"));
	FRotator objectRotation = FRotator();
	SpawnObject(GetActorLocation(), objectRotation);
}

void ABaseFood::SpawnObject(FVector Loc, FRotator Rot)
{
	FActorSpawnParameters SpawnParams;
	AFlexActor* SpawnedActorRef = GetWorld()->SpawnActor<AFlexActor>(ActorToSpawn, Loc, Rot, SpawnParams);
}

