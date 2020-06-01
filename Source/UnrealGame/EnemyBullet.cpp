// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBullet.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "UnrealGame/UnrealGameCharacter.h"

// Sets default values
AEnemyBullet::AEnemyBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	URoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	//UMyWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("widget"));
	USphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerCollider"));

	UStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	UStaticMesh->SetupAttachment(URoot);
	USphereCollider->SetupAttachment(UStaticMesh);
}

// Called when the game starts or when spawned
void AEnemyBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AEnemyBullet::NotifyActorBeginOverlap(AActor* Other)
{
	AUnrealGameCharacter* Pawn = Cast<AUnrealGameCharacter>(Other);

	//UE_LOG(LogTemp, Log, TEXT("We hit ndea!"));
	if (IsValid(Pawn))
	{
		Pawn->FGetDamage(FDamage);
		Destroy();
	}

}

void AEnemyBullet::NotifyActorEndOverlap(AActor* Other)
{
	AActor* Pawn = Cast<AActor>(Other);
	if (IsValid(Pawn)) {
		
	}

}

