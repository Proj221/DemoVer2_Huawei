// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemoVer2GameMode.h"
#include "DemoVer2Character.h"
#include "UObject/ConstructorHelpers.h"

ADemoVer2GameMode::ADemoVer2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
