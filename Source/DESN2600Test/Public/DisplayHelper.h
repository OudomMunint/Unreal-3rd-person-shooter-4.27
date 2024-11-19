

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DisplayHelper.generated.h"

UCLASS()
class DESN2600TEST_API ADisplayHelper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADisplayHelper();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Display")
	void GetRefreshRate();

};
