#include "../../include/ECS/EntityManager.h"

vector<SystemThread*> EntityManager::ExecuteSystems()
{
    vector<SystemThread*> threads;
    for(auto& archetype : archetypes)
    {
        archetype.ExecuteSystems(threads);
    }

    return threads;
}