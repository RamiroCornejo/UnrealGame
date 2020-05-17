// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealGame/UnrealGameCharacter.h"
#include "GameFramework/GameModeBase.h"
#include "MyLevelGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAME_API AMyLevelGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	void restart(AUnrealGameCharacter* character);
	UPROPERTY(EditDefaultsOnly)
		FString MapName;
		
};
