#include "EntityManager.h"
#include "Entity.h"
#include "Archetype.h"
#include <vector>
#include <array>
#include <typeinfo>

using namespace std;

template <class T, class... Ts>
void GetHashesRecursive(vector<size_t> &hashes, T const& first, Ts const&... rest)
{
    hashes.push_back(typeid(T).hash_code());
    if constexpr (sizeof...(rest) > 0)
    {
        GetHashesRecursive(hashes, rest...);
    }
}

template <class... Ts>
vector<size_t> GetHashes(Ts const&... rest)
{
    int hashesCount = sizeof...(rest);
    vector<size_t> hashes(hashesCount);
    GetHashesRecursive(hashes, rest...);
    return hashes;
}


Archetype& GetArchetype(vector<Archetype>& archetypes, vector<size_t>& typesHashes)
{
    for(auto& archetype : archetypes)
    {
        if(archetype.TypesHashes() == typesHashes)
        {
            cout << 0;
            return archetype;
        }
    }

    archetypes.push_back(Archetype(typesHashes));
    return archetypes[archetypes.size() - 1];
}

template<class... Types>
Entity EntityManager::Create(Types const&... components)
{
    auto hashes = GetHashes(components...);
    auto archetype = GetArchetype(archetypes, hashes);

    return Entity();
}