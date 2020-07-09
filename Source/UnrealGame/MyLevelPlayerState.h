// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MyLevelPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAME_API AMyLevelPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		int lifes;

	void Death();
};
