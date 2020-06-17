// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLevelGameMode.h"
#include "MyLevelPlayerState.h"

void AMyLevelGameMode::Restart(AUnrealGameCharacter* character) {
	AMyLevelPlayerState* myState = Cast<AMyLevelPlayerState>(GetWorld()->GetFirstPlayerController()->PlayerState);
	myState->lifes--;

	/*if (myState->lifes == 0) {
		GetWorld()->ServerTravel(MapName);
	}*/
	//else {
		character->Destroy();
		RestartPlayer(GetWorld()->GetFirstPlayerController());
	//}


	//GetDefaultPawnClassForController_Implementation(character->Controller);*/

}
void AMyLevelGameMode::LoadLevel(FString mapName) {
	GetWorld()->ServerTravel(mapName);
}
