#include "../../include/ECS/EntityManager.h"

void System::InternalInit(EntityManager &entityManager)
{
    this->entityManager = &entityManager;
    Initialize();
}