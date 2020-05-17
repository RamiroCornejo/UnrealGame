// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerWidget.h"
#include "UMG/Public/Components/ProgressBar.h"
void UMyPlayerWidget::UpdateLifeBar(float value) {

	HeatlhBar->SetPercent(value);
}

