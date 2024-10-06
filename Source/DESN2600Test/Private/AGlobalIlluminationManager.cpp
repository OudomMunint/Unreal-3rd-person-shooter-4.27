#include "AGlobalIlluminationManager.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"
#include "HAL/IConsoleManager.h"
#include "Scalability.h"
#include "AShadowManager.h"

// Sets default values
AAGlobalIlluminationManager::AAGlobalIlluminationManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Cache current GI quality level
	int32 CachedGIQuality = Scalability::GetQualityLevels().GlobalIlluminationQuality;

    ApplyGISettings(CachedGIQuality);
}

// Called when the game starts or when spawned
void AAGlobalIlluminationManager::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AAGlobalIlluminationManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Check for change
    int32 CurrentGIQuality = Scalability::GetQualityLevels().GlobalIlluminationQuality;

    if (CurrentGIQuality != CachedGIQuality)
    {
        ApplyGISettings(CurrentGIQuality);
        CachedGIQuality = CurrentGIQuality;
    }
}

void AAGlobalIlluminationManager::ApplyGISettings(int32 GiQualityLevel)
{
    if (Scalability::GetQualityLevels().GlobalIlluminationQuality <= 1)
    {
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.DynamicGlobalIlluminationMethod"))->Set(2);
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.ReflectionMethod"))->Set(2);
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.SSGI.Quality"))->Set(4);

         UE_LOG(LogTemp, Warning, TEXT("Lumen is disabled"));
         UE_LOG(LogTemp, Warning, TEXT("SSGI fallback is enabled"));
         UE_LOG(LogTemp, Warning, TEXT("SSR fallback is enabled"));
    }
    else if (Scalability::GetQualityLevels().GlobalIlluminationQuality > 1)
    {
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.DynamicGlobalIlluminationMethod"))->Set(1);
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.ReflectionMethod"))->Set(1);

        UE_LOG(LogTemp, Warning, TEXT("Lumen GI & Reflections is enabled"));
    }
}