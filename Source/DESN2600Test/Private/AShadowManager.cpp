#include "AShadowManager.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"
#include "HAL/IConsoleManager.h"
#include "Scalability.h"

// Sets default values
AAShadowManager::AAShadowManager()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

	// Cache current shadow quality level
    CachedShadowQuality = Scalability::GetQualityLevels().ShadowQuality;
    ApplyShadowSettings(CachedShadowQuality);
}

// Called when the game starts or when spawned
void AAShadowManager::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AAShadowManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    int32 CurrentShadowQuality = Scalability::GetQualityLevels().ShadowQuality;

    if (CurrentShadowQuality != CachedShadowQuality)
    {
        ApplyShadowSettings(CurrentShadowQuality);
        CachedShadowQuality = CurrentShadowQuality;
    }
}

void AAShadowManager::ApplyShadowSettings(int32 ShadowQualityLevel)
{
    if (ShadowQualityLevel <= 1)
    {
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.Shadow.Virtual.Enable"))->Set(0);
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.VolumetricFog"))->Set(1);
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.Shadow.CSM.MaxCascades"))->Set(3);
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.Shadow.MaxCSMResolution"))->Set(2048);

        UE_LOG(LogTemp, Warning, TEXT("Virtual shadow map disabled"));
        UE_LOG(LogTemp, Warning, TEXT("Volumetric Fog overridden"));
    }
    else if (ShadowQualityLevel > 1)
    {
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.Shadow.Virtual.Enable"))->Set(1);
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.VolumetricFog"))->Set(1);
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.Shadow.CSM.MaxCascades"))->Set(4);

        UE_LOG(LogTemp, Warning, TEXT("Virtual shadow map enabled"));
    }
    else if (ShadowQualityLevel == 0)
    {
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.VolumetricFog"))->Set(0);
        UE_LOG(LogTemp, Warning, TEXT("Volumetric Fog disabled"));
    }
}