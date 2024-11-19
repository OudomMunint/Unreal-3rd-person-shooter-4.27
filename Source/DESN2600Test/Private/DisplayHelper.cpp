

//#include "UMyDisplayHelper.h"
#include "DisplayHelper.h"
//#include "GenericPlatform/GenericApplication.h"
//#include "HAL/PlatformApplicationMisc.h"
//#include "Windows/WindowsApplication.h" // Include the Windows specific header
//#include "RHI.h"
//#include "Engine/Engine.h"

// Sets default values
ADisplayHelper::ADisplayHelper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADisplayHelper::BeginPlay()
{
	Super::BeginPlay();

	FScreenResolutionArray Resolutions;
	if (RHIGetAvailableResolutions(Resolutions, false))
	{
		// Process the resolutions array to get the refresh rate
		for (const FScreenResolutionRHI& Resolution : Resolutions)
		{
			UE_LOG(LogTemp, Log, TEXT("Resolution: %dx%d @ %dHz"), Resolution.Width, Resolution.Height, Resolution.RefreshRate);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get available resolutions."));
	}
	
}

// Called every frame
void ADisplayHelper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADisplayHelper::GetRefreshRate()
{
	FScreenResolutionArray Resolutions;
	if (RHIGetAvailableResolutions(Resolutions, false))
	{
		// Process the resolutions array to get the refresh rate
		for (const FScreenResolutionRHI& Resolution : Resolutions)
		{
			UE_LOG(LogTemp, Log, TEXT("Resolution: %dx%d @ %dHz"), Resolution.Width, Resolution.Height, Resolution.RefreshRate);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get available resolutions."));
	}
}