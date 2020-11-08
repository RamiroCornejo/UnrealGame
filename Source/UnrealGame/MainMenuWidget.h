// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAME_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta = (BindWidget))
	class UButton* Button_Play;


	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void OnButtonPlayClicked();

public:
	UPROPERTY(EditDefaultsOnly)
	FString MapName;
	
};
