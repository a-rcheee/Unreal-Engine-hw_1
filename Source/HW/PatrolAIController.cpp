
#include "PatrolAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"

void APatrolAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (!InPawn)
        return;

    if (BehaviorTreeAsset && BehaviorTreeAsset->BlackboardAsset)
    {
        UBlackboardComponent* BB = nullptr;

        if (UseBlackboard(BehaviorTreeAsset->BlackboardAsset, BB))
        {
            BB->SetValueAsVector(
                TEXT("PatrolOrigin"),
                InPawn->GetActorLocation()
            );

            RunBehaviorTree(BehaviorTreeAsset);
        }
    }

    GetWorldTimerManager().SetTimer(
        DetectionTimerHandle,
        this,
        &APatrolAIController::UpdatePlayerDetection,
        0.2f,
        true
    );

    UpdatePlayerDetection();
}

void APatrolAIController::UpdatePlayerDetection()
{
    APawn* EnemyPawn = GetPawn();
    UBlackboardComponent* BB = GetBlackboardComponent();

    if (!EnemyPawn || !BB)
        return;

    APawn* PlayerPawn =
        UGameplayStatics::GetPlayerPawn(this, 0);

    bool bShouldChase = false;

    if (PlayerPawn && PlayerPawn != EnemyPawn)
    {
        float Distance = FVector::Dist(
            EnemyPawn->GetActorLocation(),
            PlayerPawn->GetActorLocation()
        );

        bool bWasChasing =
            BB->GetValueAsObject(TEXT("TargetActor")) != nullptr;

        bShouldChase =
            Distance <= DetectionRadius ||
            (bWasChasing && Distance <= LoseTargetRadius);
    }

    if (bShouldChase)
    {
        BB->SetValueAsObject(
            TEXT("TargetActor"), PlayerPawn
        );
    }
    else
    {
        BB->ClearValue(TEXT("TargetActor"));
    }

    if (ACharacter* Enemy = Cast<ACharacter>(EnemyPawn))
    {
        Enemy->GetCharacterMovement()->MaxWalkSpeed =
            bShouldChase ? ChaseSpeed : PatrolSpeed;
    }
}
