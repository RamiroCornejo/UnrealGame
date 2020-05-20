// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/WidgetComponent.h"
#include "UnrealGame/MyPlayerWidget.h"
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
		USceneComponent* Root;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollider;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(BlueprintReadWrite)
		 UWidgetComponent* UMyWidget;
	UPROPERTY(EditAnywhere)
		float FMaxHealth;
	float FCurrentHealth;
	
	UPROPERTY(BlueprintReadWrite)
		 UMyPlayerWidget* UBarLife;
	FTimerHandle TimerHandle;
	void tickDamage();
public:	
	// Called every frame
	UFUNCTION(BlueprintCallable)
		void FGetDamage(float damage);
	UFUNCTION(BlueprintCallable)
		void FGetWidget(UWidgetComponent* widget);
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
