// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemyBase.h"
#include "UnrealGame/MyPlayerWidget.h"
#include "Components/WidgetComponent.h"
#include "Components/BoxComponent.h"
#include "EngineUtils.h"
#include "UnrealGame/UnrealGameCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyEnemyBase::AMyEnemyBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	URoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	//UMyWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("widget"));
	UBoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerCollider"));

	UStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));

	UStaticMesh->SetupAttachment(URoot);
	UBoxCollider->SetupAttachment(UStaticMesh);
	
}

// Called when the game starts or when spawned
void AMyEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
	FCurrentHealth = FMaxHealth;
	
	
	if (UBarLife == nullptr) {
		UE_LOG(LogTemp, Log, TEXT("nulo"));
	}
	
}

// Called every frame
void AMyEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (APlayer != nullptr) {
		FVector TargetPosition = APlayer->GetActorLocation();		
		FVector myPosition = FVector(GetActorLocation().X, GetActorLocation().Y,0.f);
		FVector playerPos= FVector(TargetPosition.X, TargetPosition.Y, 0.f);
		FVector Forward = playerPos-myPosition;
		FVector WorldUp = FVector::UpVector;
		FRotator Rot = UKismetMathLibrary::MakeRotFromXZ(Forward, WorldUp);
		SetActorRotation(Rot);
	}
	else {
		GetPlayer();
	}
}

// Called to bind functionality to input
void AMyEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void AMyEnemyBase::FGetDamage(float damage)
{
	FCurrentHealth -= damage;
	float FPercentage = FCurrentHealth / FMaxHealth;
	UBarLife->FUpdateLifeBar(FPercentage);
	
}
void AMyEnemyBase::FGetWidget(UWidgetComponent* widget)
{
	UMyWidget = widget;
}
void AMyEnemyBase::GetPlayer()
{
	//for (TActorIterator<AUnrealGameCharacter> It(GetWorld()); It; ++It)
	//{
	//	APlayer = *It;
	//	// ...
	//}
	APlayer = Cast<AUnrealGameCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (APlayer != nullptr) {
		UE_LOG(LogTemp, Log, TEXT("tengo al player"));
	}
}
void AMyEnemyBase::RemovePlayer()
{
	APlayer = nullptr;
}

