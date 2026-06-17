// Copyright Epic Games, Inc. All Rights Reserved.

#include "Assignment10GameMode.h"
#include "Assignment10Character.h"
#include "UObject/ConstructorHelpers.h"

AAssignment10GameMode::AAssignment10GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
