

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGlobalIlluminationManager.generated.h"

UCLASS()
class DESN2600TEST_API AAGlobalIlluminationManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGlobalIlluminationManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Global vars
	int32 CachedGIQuality = Scalability::GetQualityLevels().GlobalIlluminationQuality;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Global Illumination")
	void ApplyGISettings(int32 GiQualityLevel);
};