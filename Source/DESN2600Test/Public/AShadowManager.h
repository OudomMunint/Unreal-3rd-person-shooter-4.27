

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AShadowManager.generated.h"

UCLASS()
class DESN2600TEST_API AAShadowManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAShadowManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Global vars
	int32 CachedShadowQuality = Scalability::GetQualityLevels().ShadowQuality;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Shadows")
	void ApplyShadowSettings(int32 ShadowQualityLevel);
};