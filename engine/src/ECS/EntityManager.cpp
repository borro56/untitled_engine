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
        ExecuteSystems();
    }
}

void EntityManager::Stop()
{
    running = false;
}

template<class SystemType, class... SystemTypes>
void EntityManager::GetOrCreateSystems()
{
    GetOrCreateSystem<SystemType>();

    if constexpr (sizeof...(SystemTypes) > 0)
    {
        GetOrCreateSystems<SystemTypes...>();
    }
}