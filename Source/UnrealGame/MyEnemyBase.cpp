// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemyBase.h"
#include "UnrealGame/MyPlayerWidget.h"
#include "Components/WidgetComponent.h"
#include "Components/BoxComponent.h"
#include "EngineUtils.h"
#include "UnrealGame/UnrealGameCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "UnrealGame/EnemyBullet.h"
#include "Components/SkeletalMeshComponent.h"
#include "MyAnimInstance.h"

// Sets default values
AMyEnemyBase::AMyEnemyBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	URoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	//UMyWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("widget"));
	UBoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerCollider"));

	UStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	USkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComp"));
	UHeadCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("HeadCollider"));

	UStaticHeadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadMesh"));

	UStaticMesh->SetupAttachment(URoot);
	USkeletalMesh->SetupAttachment(URoot);
	UBoxCollider->SetupAttachment(UStaticMesh);
	UStaticHeadMesh->SetupAttachment(URoot);
	UHeadCollider->SetupAttachment(UStaticHeadMesh);
	
}

// Called when the game starts or when spawned
void AMyEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	//auto* anim = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	
	MyAnim = Cast<UMyAnimInstance>(USkeletalMesh->GetAnimInstance());

	FCurrentHealth = FMaxHealth;
	
	SpawnPos = GetActorLocation();
	
}

// Called every frame
void AMyEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bAlarm) {
		return;
	}
	if (APlayer != nullptr) {
		FVector TargetPosition = APlayer->GetActorLocation();		
		FVector myPosition = FVector(GetActorLocation().X, GetActorLocation().Y,0.f);
		FVector playerPos= FVector(TargetPosition.X, TargetPosition.Y, 0.f);
		FVector Forward = playerPos-myPosition;
		FVector WorldUp = FVector::UpVector;
		FRotator Rot = UKismetMathLibrary::MakeRotFromXZ(Forward, WorldUp);
		SetActorRotation(Rot);
		if (MyAnim != nullptr)
		{
			MyAnim->bWalk = true;
		}

		float distance = GetDistanceTo(APlayer);
		if (distance > FMaxDistance) {
			//FString IntAsString = FString::FromInt(distance);
			FVector location = GetActorLocation();
			location += GetActorForwardVector()*FSpeed;
			SetActorLocation(location);
			if (shootTest == false) {
				FActorSpawnParameters ActorSpawnParams;
				GetWorld()->SpawnActor<AEnemyBullet>(TMyBullet, GetActorLocation(), GetActorRotation(), ActorSpawnParams);
				shootTest = true;
				
				if (MyAnim != nullptr)
				{
					MyAnim->bWalk = false;
					MyAnim->bShoot = true;
				}
			}

		}
		else {
			shootTest = false;
			if (MyAnim != nullptr)
			{
				
				MyAnim->bShoot = false;
			}
		}
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
	if (FCurrentHealth <= 0) {
		if (FLives > 0) {
			FRevive();
			FLives--;
		}
		else {
			Destroy();
		}
		
	}
	
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
void AMyEnemyBase::FRevive()
{
	SetActorLocation(SpawnPos);
	FCurrentHealth = FMaxHealth;
	UBarLife->FUpdateLifeBar(1);
}

