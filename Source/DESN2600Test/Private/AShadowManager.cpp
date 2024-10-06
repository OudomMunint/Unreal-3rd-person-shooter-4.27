#include "Engine/World.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"
#include "AShadowManager.h"

// Sets default values
AAShadowManager::AAShadowManager()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;;
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
}