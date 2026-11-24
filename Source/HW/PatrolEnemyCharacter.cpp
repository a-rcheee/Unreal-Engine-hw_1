
#include "PatrolEnemyCharacter.h"
#include "PatrolAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

APatrolEnemyCharacter::APatrolEnemyCharacter()
{
    AIControllerClass = APatrolAIController::StaticClass();

    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    bUseControllerRotationYaw = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;

    GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
}
