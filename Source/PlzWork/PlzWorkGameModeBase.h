// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlzWorkGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PLZWORK_API APlzWorkGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	APlzWorkGameModeBase();
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class UFMODAudioComponent* FMODAudio;
};
