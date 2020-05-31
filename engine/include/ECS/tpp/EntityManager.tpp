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

    archetypes.push_back(Archetype::Create<Types...>(*this));

    auto& newArcehtype = archetypes[archetypes.size() - 1];

    for(auto system : systems)
    {
        if(system->SubsetOf(newArcehtype))
        {
            newArcehtype.AddSystem(system);
        }
    }



    return newArcehtype;
}

template<class... Types> vector<Archetype*> EntityManager::GetArchetypes()
{
    vector<Archetype*> matchingArchetypes;

    for(auto& archetype : archetypes)
    {
        if(archetype.ContainsTypes<Types...>())
        {
            matchingArchetypes.push_back(&archetype);
        }
    }

    return matchingArchetypes;
}

template<class SystemType>
shared_ptr<SystemType> EntityManager::GetOrCreateSystem()
{
    auto system = make_shared<SystemType>();
    system->Init(*this);
    systems.push_back(system);
    return system;
}

