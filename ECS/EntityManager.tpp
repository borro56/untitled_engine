#include "EntityManager.h"
#include "Entity.h"
#include "Archetype.h"
#include <vector>
#include <array>
#include <typeinfo>

using namespace std;

template <class T, class... Ts>
void GetHashes(vector<size_t> &hashes, int& size, T const& first, Ts const&... rest)
{
    size += sizeof(T);
    hashes.push_back(typeid(T).hash_code());
    if constexpr (sizeof...(rest) > 0)
    {
        GetHashes(hashes, size, rest...);
    }
}


Archetype* GetArchetype(vector<Archetype>& archetypes, vector<size_t>& typesHashes, int size)
{
    for(auto& archetype : archetypes)
    {
        if(archetype.TypesHashes() == typesHashes)
        {
            return &archetype;
        }
    }

    archetypes.push_back(Archetype(typesHashes, size));
    return &archetypes[archetypes.size() - 1]; //TODO: Ver porque no puedo retornar referencias
}

template<class... Types>
Entity EntityManager::Create(Types const&... components)
{
    int size = 0;
    vector<size_t> hashes;
    hashes.reserve(sizeof...(components));
    GetHashes(hashes, size, components...);
    sort(hashes.begin(), hashes.end());

    auto archetype = GetArchetype(archetypes, hashes, size);
    archetype->AddEntity(components...);
    return Entity();
}