#include "TpsGameInstance.h"
#include "Engine/Engine.h"
#include "HAL/IConsoleManager.h"
#include "Scalability.h"

// Init() is called when the Game Instance is initialized
//void UTpsGameInstance::Init()
//{
//    
//
//    // Cache the initial GI quality when the engine starts
//    CachedGIQuality = Scalability::GetQualityLevels().GlobalIlluminationQuality;
//
//    // Apply initial GI settings
//    ApplyGISettings(CachedGIQuality);
//}

void UTpsGameInstance::ApplyGISettings(int32 GiQualityLevel)
{
    if (GiQualityLevel == 1)
    {
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.DynamicGlobalIlluminationMethod"))->Set(2);
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.ReflectionMethod"))->Set(2);
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.SSGI.Quality"))->Set(4);

        UE_LOG(LogTemp, Warning, TEXT("Lumen disabled, SSGI fallback enabled"));
    }
    else if (GiQualityLevel == 0)
    {
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.SSGI.Quality"))->Set(0);
        UE_LOG(LogTemp, Warning, TEXT("SSGI disabled"));
    }
    else if (GiQualityLevel > 1)
    {
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.DynamicGlobalIlluminationMethod"))->Set(1);
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.ReflectionMethod"))->Set(1);
        UE_LOG(LogTemp, Warning, TEXT("Lumen GI & Reflections enabled"));
    }
}

void UTpsGameInstance::CheckForGIQualityChange()
{
    int32 CurrentGIQuality = Scalability::GetQualityLevels().GlobalIlluminationQuality;
    if (CurrentGIQuality != CachedGIQuality)
    {
        ApplyGISettings(CurrentGIQuality);
        CachedGIQuality = CurrentGIQuality;
    }
}