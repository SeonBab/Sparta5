// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();


	for (int i = 0; i < 10; ++i)
	{
		FVector2D PreviousPosition = start;

		// 이동
		move();

		// 이동한 거리 출력
		float CurrentDistance = distance(PreviousPosition, start);
		UE_LOG(LogTemp, Log, TEXT("Current Distance: %f"), CurrentDistance);

		// 이벤트 
		bool bTriggerEvent = static_cast<bool>(createEvent());
		startEvent(bTriggerEvent);

		UE_LOG(LogTemp, Log, TEXT("============================="));
	}
	// 이동한 거리 총합
	totDist = distance(FVector2D::ZeroVector, start);

	// 이동한 거리 총합 출력
	UE_LOG(LogTemp, Log, TEXT("Total Distance: %f"), totDist);
	// 발생한 이벤트 총합 출력
	UE_LOG(LogTemp, Log, TEXT("Event Count: %d"), evCnt);
}

void AMyActor::move()
{
	// step함수에서 반환된 이동할 거리를 기존 위치에서 더해줌
	start.X = start.X + step();
	start.Y = start.Y + step();

	// 이동한 위치 출력
	UE_LOG(LogTemp, Log, TEXT("Current Location: %s"), *start.ToString());
}

int32 AMyActor::step()
{
	// 이동할 거리 최소값과 최대값
	const int32 MinNumber = 0;
	const int32 MaxNumber = 1;

	// 이동할 거리
	int32 RandomNumber = FMath::RandRange(MinNumber, MaxNumber);

	// 이동할 거리 반환
	return RandomNumber;
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	// 이동한 거리 구하는 연산 및 반환
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;

	dx *= dx;
	dy *= dy;
	
	return FMath::Sqrt(dx + dy);
}

int32 AMyActor::createEvent()
{	
	// 이벤트가 발생할 확률이 50%이므로 RandBool 사용
	return FMath::RandBool();
}

void AMyActor::startEvent(bool bTriggerEvent)
{
	// 조건에 따라 이벤트 실행
	if (true == bTriggerEvent)
	{
		++evCnt;

		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Event Not Triggered"));
	}
}
