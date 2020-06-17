// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGrenade.h"
#include "DrawDebugHelpers.h"
#include "CollisionShape.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "UnrealGame/MyEnemyBase.h"

// Sets default values
AMyGrenade::AMyGrenade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AMyGrenade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyGrenade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentTime += DeltaTime;
	if (CurrentTime >= Timer&&bExploted) {
		Explode();
		bExploted=false;
		Destroy();
	}

}
void AMyGrenade::Explode()
{
	TArray<FHitResult> Outhits;
	FVector location = GetActorLocation();
	FCollisionShape myColSphere = FCollisionShape::MakeSphere(Range);
	//bool hit = GetWorld()->SweepMultiByChannel(Outhits, location, location, FQuat::Identity, ECollisionChannel::ECC_PhysicsBody, myColSphere);
	if (GetWorld()->SweepMultiByChannel(Outhits, location, location, FQuat::Identity, ECollisionChannel::ECC_PhysicsBody, myColSphere)) {
		for (auto& Hit : Outhits) {

			AMyEnemyBase* myEnemy = Cast<AMyEnemyBase>(Hit.Actor.Get());
			if (IsValid(myEnemy)) {
				myEnemy->_TakeDamage(Damage);
			}
		}
	}
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionParticle, GetActorLocation());

}

