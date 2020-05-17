// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyPlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAME_API UMyPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void UpdateLifeBar(float value);
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UProgressBar* HeatlhBar;
};
