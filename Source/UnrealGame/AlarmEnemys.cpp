// Fill out your copyright notice in the Description page of Project Settings.


#include "AlarmEnemys.h"
#include "UnrealGame/MyEnemyBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UnrealGame/UnrealGameCharacter.h"

// Sets default values
AAlarmEnemys::AAlarmEnemys()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	URoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	//UMyWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("widget"));
	UBoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerCollider"));

	UStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	UStaticMesh->SetupAttachment(URoot);
	UBoxCollider->SetupAttachment(UStaticMesh);

}

// Called when the game starts or when spawned
void AAlarmEnemys::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAlarmEnemys::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAlarmEnemys::NotifyActorBeginOverlap(AActor* Other)
{
	AUnrealGameCharacter* Pawn = Cast<AUnrealGameCharacter>(Other);

	//UE_LOG(LogTemp, Log, TEXT("We hit ndea!"));
	if (IsValid(Pawn))
	{
		for (int i = 0; i < GroupOfEnemys.Num(); i++)
		{
			GroupOfEnemys[i]->bAlarm = true;
		}
		Destroy();
	}


}

