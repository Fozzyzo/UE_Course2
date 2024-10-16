// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StartingPosition = FVector::ZeroVector;
	Displacement = FVector::ZeroVector;
	MaximumDistance = 200.0f;
	DeltaDistance = 0.0f;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartingPosition = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("Configured Displacement: x=%f y=%f z=%f"), Displacement.X, Displacement.Y, Displacement.Z);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Velocity = Displacement * DeltaTime;
	FVector NewLocation = GetActorLocation() + Velocity;
	DeltaDistance = FVector::Dist(StartingPosition, NewLocation);

	if (DeltaDistance > MaximumDistance)
	{
		Displacement = -Displacement;
		return;
	}
	
	SetActorLocation(NewLocation);
}

