
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PatrolAIController.generated.h"

class UBehaviorTree;

UCLASS()
class HW_API APatrolAIController : public AAIController
{
    GENERATED_BODY()

public:
    virtual void OnPossess(APawn* InPawn) override;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "AI")
    float DetectionRadius = 900.f;

    UPROPERTY(EditDefaultsOnly, Category = "AI")
    float LoseTargetRadius = 1400.f;

    UPROPERTY(EditDefaultsOnly, Category = "AI")
    float PatrolSpeed = 180.f;

    UPROPERTY(EditDefaultsOnly, Category = "AI")
    float ChaseSpeed = 420.f;

private:
    FTimerHandle DetectionTimerHandle;

    void UpdatePlayerDetection();
};
