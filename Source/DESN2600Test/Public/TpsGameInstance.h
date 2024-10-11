

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TpsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DESN2600TEST_API UTpsGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
    // Called when the subsystem initializes (on game start)
    //virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    // Method to apply GI settings
    void ApplyGISettings(int32 GiQualityLevel);

    // Method to check and update GI settings if they change
    void CheckForGIQualityChange();

private:
    // Store the cached GI quality
    int32 CachedGIQuality;
};
