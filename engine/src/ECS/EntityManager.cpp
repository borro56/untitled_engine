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
    cout << "-- " << entitiesToDelete.size() << "\n";
    for (auto entityId : entitiesToDelete)
    {
        auto& entityData = entityMap[entityId];
        auto& archetype = archetypes[entityData.archetypeIndex];
        auto& chunk = archetype.chunks[entityData.chunkIndex];

        cout << "- " << entityId << ' ' << (short)entityData.archetypeIndex << ' ' << (short)entityData.chunkIndex << ' ' << (short)entityData.entityIndex << '\n';

        for(auto& componentType : archetype.componentTypes)
        {
            auto array = chunk->GetArrayBase(componentType);
            auto lastElementIndex = (chunk->amount - 1) * componentType.Size();
            auto toDeleteElementIndex = entityData.entityIndex * componentType.Size();

            copy(array + lastElementIndex,
                    array + lastElementIndex + componentType.Size(),
                    array + toDeleteElementIndex);
        }

        auto movedEntityData = EntityData { entityData.archetypeIndex, entityData.chunkIndex, (short)(chunk->amount - 1)  };
        auto movedEntityIndex = entityDataMap[movedEntityData];

        entityMap[movedEntityIndex] = entityData;
        entityDataMap[entityData] = movedEntityIndex;

        entityMap.erase(entityId);
        entityDataMap.erase(movedEntityData);

        //TODO: Reuse entity ids

        chunk->amount--;
        chunk->activeAmount--;
        archetype.activeChunksAmount--;
        entityCount--;

        cout << "* " << entityMap.size() << ' ' << entityDataMap.size() << '\n';

    }

    entitiesToDelete.clear();
}