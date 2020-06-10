// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AlarmEnemys.generated.h"

UCLASS()
class UNREALGAME_API AAlarmEnemys : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAlarmEnemys();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
		USceneComponent* URoot;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* UBoxCollider;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* UStaticMesh;

	UPROPERTY(EditAnywhere)
		TArray<class AMyEnemyBase*> GroupOfEnemys;
	
	UFUNCTION()
		virtual void NotifyActorBeginOverlap(AActor* Other) override;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
