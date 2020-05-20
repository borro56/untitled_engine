#ifndef UNTITLED_SYSTEM_H
#define UNTITLED_SYSTEM_H

#include <cstdio>
#include "Chunk.h"
#include "Archetype.h"
#include "ComponentType.h"

template<class... Types>
class System
{
    template<class T> T* GetComponentArray(Chunk& chunk, const Archetype& archetype);
    template<class T> T& GetComponentRef(T* array, int index);
    void InternalExecuteArray(Chunk& chunk, Types*... types);

protected:
    virtual void InternalExecute(Types&... types) = 0;

public:
    void Execute(Chunk& chunk, const Archetype& archetype);
};

template<class... Types>
template<class T>
T* System<Types...>::GetComponentArray(Chunk& chunk, const Archetype& archetype)
{
    auto& type = archetype.GetType<T>();
    return chunk.GetArray(type);
}

template<class... Types>
void System<Types...>::Execute(Chunk& chunk, const Archetype& archetype)
{
    InternalExecuteArray(chunk, GetComponentArray<Types>(chunk, archetype)...);
}

template<class... Types>
template<class T>
T& System<Types...>::GetComponentRef(T* array, int index)
{
    return array[index];
}

template<class... Types>
void System<Types...>::InternalExecuteArray(Chunk& chunk, Types *... types)
{
    for (int i = 0; i < chunk.Count(); ++i)
    {
        InternalExecute(GetComponentRef<Types>(types, i)...);
    }
}

#endif