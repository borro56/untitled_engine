//
// Created by Nicolas Borromeo on 22/05/2020.
//

#include "../../include/ECS/EntityManager.h"

void System::Init(EntityManager &entityManager)
{
    this->entityManager = &entityManager;
}