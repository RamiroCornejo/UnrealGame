// Fill out your copyright notice in the Description page of Project Settings.


#include "EndOfLevel.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "UnrealGame/UnrealGameCharacter.h"
#include "UnrealGame/MyLevelGameMode.h"
// Sets default values
AEndOfLevel::AEndOfLevel()
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
void AEndOfLevel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEndOfLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEndOfLevel::NotifyActorBeginOverlap(AActor* Other)
{
	AUnrealGameCharacter* Pawn = Cast<AUnrealGameCharacter>(Other);

	//UE_LOG(LogTemp, Log, TEXT("We hit ndea!"));
	if (IsValid(Pawn))
	{
		AMyLevelGameMode* myGamemode = Cast<AMyLevelGameMode>(GetWorld()->GetAuthGameMode());
		if (myGamemode != nullptr) {
			myGamemode->LoadLevel(MapName);
		}
	}


}

