
#include "../EntitySystem.h"
#include "../EntityManager.h"

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
void EntitySystem<Types...>::Execute(Archetype& archetype, Chunk& chunk)
{
    InternalExecuteArray(chunk, GetComponentArray<Types>(archetype, chunk)...);
}

template<class... Types>
void EntitySystem<Types...>::InternalExecuteArray(Chunk& chunk, Types *... types)
{
    for (int i = 0; i < chunk.Count(); ++i)
    {
        InternalExecute(GetComponentRef<Types>(types, i)...);
    }
}

template<class... Types>
void EntitySystem<Types...>::Init(EntityManager &entityManager)
{
    System::Init(entityManager);

    auto archetypes = entityManager.GetArchetypes<Types...>();
    for(auto archetype : archetypes)
    {
        archetype->AddSystem(shared_from_this());
    }

    InternalInit();
}

template<class... Types>
vector<Archetype *> EntitySystem<Types...>::GetArchetypes()
{
    return entityManager->GetArchetypes<Types...>();
}

template<class... Types>
bool EntitySystem<Types...>::SubsetOf(Archetype &archetype)
{
    return archetype.ContainsTypes<Types...>();
}