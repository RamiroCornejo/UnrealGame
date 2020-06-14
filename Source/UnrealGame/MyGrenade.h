// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyGrenade.generated.h"

UCLASS()
class UNREALGAME_API AMyGrenade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyGrenade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	float FTimer;
	float FCurrentTime=0.f;
	UPROPERTY(EditAnywhere)
		float FRange;
	UPROPERTY(EditAnywhere)
		float FDamage;
	void Explode();
	bool bExploted=true;

	UPROPERTY(EditDefaultsOnly)
	class UParticleSystem* explosionParticle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
