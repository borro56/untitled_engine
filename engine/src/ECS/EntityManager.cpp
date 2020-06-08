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
        DeleteEntities();
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

void EntityManager::Delete(Entity entity)
{
    entitiesToDeleteMutex.lock();
    entitiesToDelete.push_back(entity.id);
    entitiesToDeleteMutex.unlock();
}

void EntityManager::DeleteEntities()
{
    for (auto toDeleteId : entitiesToDelete)
    {
        auto &toDeleteData = entityMap[toDeleteId];
        auto &archetype = archetypes[toDeleteData.archetypeIndex];
        auto &chunk = archetype.chunks[toDeleteData.chunkIndex];

        auto lastData = EntityData{toDeleteData.archetypeIndex, toDeleteData.chunkIndex, (short) (chunk->amount - 1)};
        auto lastId = entityDataMap[lastData];

        if(toDeleteId != lastId)
        {
            for (auto &componentType : archetype.componentTypes)
            {
                auto array = chunk->GetArrayBase(componentType);
                auto lastElementIndex = (chunk->amount - 1) * componentType.Size();
                auto toDeleteElementIndex = toDeleteData.entityIndex * componentType.Size();

                copy(array + lastElementIndex,
                     array + lastElementIndex + componentType.Size(),
                     array + toDeleteElementIndex);
            }

            entityMap[lastId] = toDeleteData;
            entityDataMap[toDeleteData] = lastId;

        }

        map<int, EntityData> prevEntityMap; prevEntityMap.insert(entityMap.begin(), entityMap.end());
        map<EntityData, int> prevEntityDataMap; prevEntityDataMap.insert(entityDataMap.begin(), entityDataMap.end());

        entityMap.erase(toDeleteId);
        entityDataMap.erase(lastData);

        chunk->amount--;
        chunk->activeAmount--;
        archetype.entityCount--;
        entityCount--;
    }

    entitiesToDelete.clear();
}