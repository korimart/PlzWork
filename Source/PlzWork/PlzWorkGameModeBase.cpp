// Copyright Epic Games, Inc. All Rights Reserved.


#include "PlzWorkGameModeBase.h"
#include "FMODEvent.h"
#include "FMODAudioComponent.h"

APlzWorkGameModeBase::APlzWorkGameModeBase()
{
	FMODAudio = CreateDefaultSubobject<UFMODAudioComponent>(TEXT("FMOD"));
}

void APlzWorkGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	TSoftObjectPtr<UFMODEvent> Event{ FSoftObjectPath{ TEXT("FMODEvent'/Game/FMOD/Events/test.test'") } };
	FMODAudio->SetEvent(Event.LoadSynchronous());
	FMODAudio->Play();

#if PLATFORM_IOS
	[[IOSAppDelegate GetDelegate] SetFeature: EAudioFeature::BluetoothMicrophone Active: YES];
	[[IOSAppDelegate GetDelegate] SetFeature: EAudioFeature::UseReceiver Active: YES];
	[[IOSAppDelegate GetDelegate] EnableVoiceChat: YES];
	[[IOSAppDelegate GetDelegate] EnableHighQualityVoiceChat: YES];
#endif
}
