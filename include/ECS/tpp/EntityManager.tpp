#include "../EntityManager.h"
#include "../Entity.h"
#include "../Archetype.h"
#include <vector>
#include <array>
#include <typeinfo>

template<class... Types> const Entity EntityManager::Create(Types const&... components)
{
    auto& archetype = GetOrCreateArchetype<Types...>();
    archetype.AddEntity(components...);
    return Entity(0); //TODO: Return actual entity
}

template <class... Types> Archetype& EntityManager::GetOrCreateArchetype()
{
    for(auto& archetype : archetypes)
    {
        if(archetype.HasTypes<Types...>())
        {
            return archetype;
        }
    }

    archetypes.push_back(Archetype::Create<Types...>());
    return archetypes[archetypes.size() - 1];
}

template<class... Types> const Archetype& EntityManager::GetArchetype() const
{
    for(auto& archetype : archetypes)
    {
        if(archetype.HasTypes<Types...>())
        {
            return archetype;
        }
    }

    throw runtime_error("No Archetype for specified types");
}
