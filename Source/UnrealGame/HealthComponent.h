// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealGame/MyPlayerWidget.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.generated.h"

UCLASS()
class UNREALGAME_API AHealthComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UMyPlayerWidget> TCharacterInfoWidgetClass;

	UPROPERTY()
		UMyPlayerWidget* ULifeBar;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetHealthBar();

	void UpdateHeatlhBar(float percentage);

	void RemoveHeatlhBar();

};
