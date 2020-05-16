#include "EntityManager.h"
#include "Entity.h"
#include "Archetype.h"
#include <vector>
#include <array>
#include <typeinfo>


template <class T, class... Ts>
int GetSize() //TODO: Move to helpers file
{
    if constexpr (sizeof...(Ts) > 0)
    {
        return sizeof(T) + GetSize<Ts...>();
    }

    return sizeof(T);
}

template <class T, class... Ts>
void GetHashesRecursive(vector<size_t> &hashes) //TODO: Move to helpers file
{
    hashes.push_back(typeid(T).hash_code());
    if constexpr (sizeof...(Ts) > 0)
    {
        GetHashesRecursive<Ts...>(hashes);
    }
}

template <class... Ts>
vector<size_t> GetHashes() //TODO: Move to helpers file
{
    vector<size_t> hashes;
    hashes.reserve(sizeof...(Ts));
    GetHashesRecursive<Ts...>(hashes);
    sort(hashes.begin(), hashes.end());
    return hashes;
}

template<class... Types>
Entity EntityManager::Create(Types const&... components)
{
    auto archetype = GetOrCreateArchetype<Types...>();
    archetype->AddEntity(components...);
    return Entity(); //TODO: Return actual entity
}

template <class... Types>
Archetype* EntityManager::GetOrCreateArchetype()
{
    auto hashes = GetHashes<Types...>();

    for(auto& archetype : archetypes)
    {
        if(archetype.HasHashes(hashes))
        {
            return &archetype;
        }
    }

    auto size = GetSize<Types...>();
    archetypes.push_back(Archetype(hashes, size));
    return &archetypes[archetypes.size() - 1]; //TODO: Ver porque no puedo retornar referencias
}

template<class... Types>
Archetype *EntityManager::GetArchetype()
{
    auto hashes = GetHashes<Types...>();

    for(auto& archetype : archetypes)
    {
        if(archetype.HasHashes(hashes))
        {
            return &archetype;
        }
    }

    return nullptr;
}
