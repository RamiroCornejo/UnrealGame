// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/Button.h"


void UMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Button_Play->OnClicked.AddUniqueDynamic(this, &ThisClass::OnButtonPlayClicked);
}

void UMainMenuWidget:: OnButtonPlayClicked()
{
	GetWorld()->ServerTravel(MapName);
}

