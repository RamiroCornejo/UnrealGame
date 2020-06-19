// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/WidgetComponent.h"
#include "UnrealGame/MyPlayerWidget.h"
#include "UnrealGame/UnrealGameCharacter.h"
#include "UnrealGame/EnemyBullet.h"
#include "MyEnemyBase.generated.h"



UCLASS()
class UNREALGAME_API AMyEnemyBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
		USceneComponent* URoot;

	UPROPERTY(EditDefaultsOnly)
		class UParticleSystem* reviveParticle;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* UBoxCollider;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* UStaticMesh;
	UPROPERTY(EditAnywhere)
		class USkeletalMeshComponent* USkeletalMesh;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AEnemyBullet> TMyBullet;
	bool shootTest;
	UPROPERTY(BlueprintReadWrite)
		 UWidgetComponent* UMyWidget;
public:
	UPROPERTY(EditAnywhere)
		class UMyAnimInstance* MyAnim;
	UPROPERTY(EditAnywhere)
		float MaxHealth;
	float CurrentHealth;
	
	UPROPERTY(BlueprintReadWrite)
		 UMyPlayerWidget* UBarLife;
	UPROPERTY()
		AUnrealGameCharacter* APlayer;
	UPROPERTY(EditAnywhere)
		float MaxDistance;
	UPROPERTY(EditAnywhere)
		float Speed;
	UPROPERTY(EditAnywhere)
		int Lives;
	FVector SpawnPos;
	void Revive();
public:	
	UPROPERTY(EditAnywhere)
		class UBoxComponent* UHeadCollider;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* UStaticHeadMesh;
	UFUNCTION(BlueprintCallable)
		void _TakeDamage(float damage);
	UFUNCTION(BlueprintCallable)
		void FGetWidget(UWidgetComponent* widget);
	virtual void Tick(float DeltaTime) override;
	void GetPlayer();
	void RemovePlayer();
	// Called to bind functionality to input
	bool bAlarm=false;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
