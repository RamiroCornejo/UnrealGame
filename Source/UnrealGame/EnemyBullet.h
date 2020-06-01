// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyBullet.generated.h"

UCLASS()
class UNREALGAME_API AEnemyBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
		USceneComponent* URoot;

	UPROPERTY(EditAnywhere)
		class USphereComponent* USphereCollider;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* UStaticMesh;
	
	UPROPERTY(EditAnywhere)
		float FDamage;
	UFUNCTION()
		virtual void NotifyActorBeginOverlap(AActor* Other) override;
	
	UFUNCTION()
		virtual void NotifyActorEndOverlap(AActor* Other) override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
