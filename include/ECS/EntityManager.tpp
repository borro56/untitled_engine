#include "EntityManager.h"
#include "Entity.h"
#include "Archetype.h"
#include <vector>
#include <array>
#include <typeinfo>

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
    for(auto& archetype : archetypes)
    {
        if(archetype.HasTypes<Types...>())
        {
            return &archetype;
        }
    }

    archetypes.push_back(Archetype::Create<Types...>());
    return &archetypes[archetypes.size() - 1]; //TODO: Ver porque no puedo retornar referencias
}

template<class... Types>
Archetype *EntityManager::GetArchetype()
{
    for(auto& archetype : archetypes)
    {
        if(archetype.HasTypes<Types...>())
        {
            return &archetype;
        }
    }

    return nullptr;
}
