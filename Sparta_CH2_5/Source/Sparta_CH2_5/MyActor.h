// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class SPARTA_CH2_5_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void move();

	int32 step();

	float distance(FVector2D first, FVector2D second);

	int32 createEvent();
	void startEvent(bool bTriggerEvent);

private:
	FVector2D start;

	int32 evCnt;
	double totDist;
};
