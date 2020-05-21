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
void System<Types...>::Execute(EntityManager& entityManager)
{
    auto archetypes = entityManager.GetArchetypes<Types...>(); //TODO: see if we can remove the vector allocation

    for (auto& archetype : archetypes)
    {
        for (int i = 0; i < archetype->ChunkCount(); ++i)
        {
            auto& chunk = archetype->GetChunkAt(i);
            InternalExecuteArray(chunk, GetComponentArray<Types>(*archetype, chunk)...);
        }
    }
}


template<class... Types>
void System<Types...>::InternalExecuteArray(Chunk& chunk, Types *... types)
{
    for (int i = 0; i < chunk.Count(); ++i)
    {
        InternalExecute(GetComponentRef<Types>(types, i)...);
    }
}