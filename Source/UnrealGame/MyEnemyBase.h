// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/WidgetComponent.h"
#include "UnrealGame/MyPlayerWidget.h"
#include "UnrealGame/UnrealGameCharacter.h"
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

	UPROPERTY(EditAnywhere)
		class UBoxComponent* UBoxCollider;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* UStaticMesh;
	
	UPROPERTY(BlueprintReadWrite)
		 UWidgetComponent* UMyWidget;
	UPROPERTY(EditAnywhere)
		float FMaxHealth;
	float FCurrentHealth;
	
	UPROPERTY(BlueprintReadWrite)
		 UMyPlayerWidget* UBarLife;
	UPROPERTY()
		AUnrealGameCharacter* APlayer;
	
	
public:	
	// Called every frame
	UFUNCTION(BlueprintCallable)
		void FGetDamage(float damage);
	UFUNCTION(BlueprintCallable)
		void FGetWidget(UWidgetComponent* widget);
	virtual void Tick(float DeltaTime) override;
	void GetPlayer();
	void RemovePlayer();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
