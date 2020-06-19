// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageArea.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UnrealGameCharacter.h"

// Sets default values
ADamageArea::ADamageArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));

	StaticMesh->SetupAttachment(Root);
	BoxCollider->SetupAttachment(StaticMesh);

}

void ADamageArea::BeginPlay()
{
	Super::BeginPlay();
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBoxColliderBeginOverlap);
	BoxCollider->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnBoxColliderEndOverlap);
	
}

void ADamageArea::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (BoxCollider->OnComponentBeginOverlap.Contains(this, TEXT("OnBoxColliderBeginOverlap")))
	{
		BoxCollider->OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnBoxColliderBeginOverlap);
	}
	if (BoxCollider->OnComponentEndOverlap.Contains(this, TEXT("OnBoxColliderEndOverlap")))
	{
		BoxCollider->OnComponentEndOverlap.RemoveDynamic(this, &ThisClass::OnBoxColliderEndOverlap);
	}
}


void ADamageArea::OnBoxColliderBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AUnrealGameCharacter* player = Cast<AUnrealGameCharacter>(OtherActor);


	if (IsValid(player))
	{
		player->_TakeDamage(Damage);

	}
}

void ADamageArea::OnBoxColliderEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{


}

void ADamageArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

