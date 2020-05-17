#include "Archetype.h"

template<class... Types> void Archetype::AddEntity(const Types &... components)
{
    GetChunk()->AddData(components...);
}

template<class Type, class... Types> void Archetype::AddType()
{
    auto componentArray = new ComponentArray<Type>();
    componentArrays.push_back(componentArray);
    entitySize += componentArray->ComponentSize();

    if constexpr (sizeof...(Types) > 0)
    {
        AddType<Types...>();
    }
}

template<class... Types> void Archetype::Init()
{
    componentArrays.reserve(sizeof...(Types));
    AddType<Types...>();

    auto entityCapacity = CHUNK_SIZE / entitySize;
    auto componentOffset = 0;

    for(auto componentArray : componentArrays)
    {
        componentArray->ChunkOffset(componentOffset);
        componentOffset += entityCapacity * componentArray->ComponentSize();
    }
}

template<class Type> ComponentArray<Type> *Archetype::GetComponentArray()
{
    auto hash = typeid(Type).hash_code();
    for(auto& array : componentArrays)
    {
        if(array->ComponentHash() == hash)
        {
            return dynamic_cast<ComponentArray<Type>*>(array);
        }
    }

    return nullptr;
}

template <class... Types> Archetype Archetype::Create()
{
    Archetype archetype;
    archetype.Init<Types...>();
    return archetype;
}

template<class... Types>
bool Archetype::HasTypes()
{
    if (sizeof...(Types) != componentArrays.size()) return false;
    return HasTypesRecursive<Types...>();
}

template<class Type, class... Types>
bool Archetype::HasTypesRecursive()
{
    auto hash = typeid(Type).hash_code();
    for(auto array : componentArrays)
    {
        if (array->ComponentHash() == hash)
        {
            if constexpr (sizeof...(Types) > 0)
            {
                return HasTypesRecursive<Types...>();
            }

            return true;
        }
    }

    return false;
}