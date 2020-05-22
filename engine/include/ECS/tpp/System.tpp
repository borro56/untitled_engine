
#include "../System.h"

template<class T>
T* GetComponentArray(const Archetype& archetype, Chunk& chunk)
{
    auto& type = archetype.GetType<T>();
    return chunk.GetArray(type);
}

template<class T>
T& GetComponentRef(T* array, int index)
{
    return array[index];
}

template<class... Types>
void System<Types...>::Execute(Archetype& archetype, Chunk& chunk)
{
    InternalExecuteArray(chunk, GetComponentArray<Types>(archetype, chunk)...);
}

template<class... Types>
void System<Types...>::InternalExecuteArray(Chunk& chunk, Types *... types)
{
    for (int i = 0; i < chunk.Count(); ++i)
    {
        InternalExecute(GetComponentRef<Types>(types, i)...);
    }
}

template<class... Types>
void System<Types...>::Init(EntityManager &entityManager)
{
    this->entityManager = &entityManager;
    auto archetypes = entityManager.GetArchetypes<Types...>();
    for(auto archetype : archetypes)
    {
        archetype->AddSystem(this);
    }
}
