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

		// �̵�
		move();

		// �̵��� �Ÿ� ���
		float CurrentDistance = distance(PreviousPosition, start);
		UE_LOG(LogTemp, Log, TEXT("Current Distance: %f"), CurrentDistance);

		// �̺�Ʈ 
		bool bTriggerEvent = static_cast<bool>(createEvent());
		startEvent(bTriggerEvent);

		UE_LOG(LogTemp, Log, TEXT("============================="));
	}
	// �̵��� �Ÿ� ����
	totDist = distance(FVector2D::ZeroVector, start);

	// �̵��� �Ÿ� ���� ���
	UE_LOG(LogTemp, Log, TEXT("Total Distance: %f"), totDist);
	// �߻��� �̺�Ʈ ���� ���
	UE_LOG(LogTemp, Log, TEXT("Event Count: %d"), evCnt);
}

void AMyActor::move()
{
	// step�Լ����� ��ȯ�� �̵��� �Ÿ��� ���� ��ġ���� ������
	start.X = start.X + step();
	start.Y = start.Y + step();

	// �̵��� ��ġ ���
	UE_LOG(LogTemp, Log, TEXT("Current Location: %s"), *start.ToString());
}

int32 AMyActor::step()
{
	// �̵��� �Ÿ� �ּҰ��� �ִ밪
	const int32 MinNumber = 0;
	const int32 MaxNumber = 1;

	// �̵��� �Ÿ�
	int32 RandomNumber = FMath::RandRange(MinNumber, MaxNumber);

	// �̵��� �Ÿ� ��ȯ
	return RandomNumber;
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	// �̵��� �Ÿ� ���ϴ� ���� �� ��ȯ
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;

	dx *= dx;
	dy *= dy;
	
	return FMath::Sqrt(dx + dy);
}

int32 AMyActor::createEvent()
{	
	// �̺�Ʈ�� �߻��� Ȯ���� 50%�̹Ƿ� RandBool ���
	return FMath::RandBool();
}

void AMyActor::startEvent(bool bTriggerEvent)
{
	// ���ǿ� ���� �̺�Ʈ ����
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
