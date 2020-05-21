#include "../../include/ECS/EntityManager.h"

void EntityManager::ExecuteSystems()
{
    for(auto& archetype : archetypes)
    {
        archetype.ExecuteSystems();
    }
}