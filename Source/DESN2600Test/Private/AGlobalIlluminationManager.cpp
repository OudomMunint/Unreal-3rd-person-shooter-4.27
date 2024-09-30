#include "AGlobalIlluminationManager.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"
#include "HAL/IConsoleManager.h"
#include "Scalability.h"

// Sets default values
AAGlobalIlluminationManager::AAGlobalIlluminationManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
}