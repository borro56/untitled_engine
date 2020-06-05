#include "../../include/ECS/EntityManager.h"

void EntityManager::ExecuteSystems()
{
    for(auto& system : systems)
    {
        system->PrepareFrame();
    }

    vector<SystemThread*> threads;
    for(auto& archetype : archetypes)
    {
        archetype.ExecuteSystems(threads);
    }

    for(auto thread : threads)
    {
        thread->Thread().join();
    }

    for(auto& system : systems)
    {
        system->FinishFrame();
    }
}

void EntityManager::Start()
{
    running = true;
    while (running)
    {
        ActivateArchetypes();
        ExecuteSystems();
    }
}

void EntityManager::ActivateArchetypes()
{
    for(auto& newArchetype : newArchetypes)
    {
        for (auto system : systems)
        {
            auto entitySystem = dynamic_pointer_cast<IEntitySystem>(system);
            if (entitySystem && entitySystem->SubsetOf(newArchetype))
            {
                newArchetype.AddSystem(entitySystem);
            }
        }
        archetypes.push_back(newArchetype);
    }
    newArchetypes.clear();

    for(auto& archetype : archetypes)
    {
        archetype.ActivateNewData();
    }
}

void EntityManager::Stop()
{
    running = false;
}

