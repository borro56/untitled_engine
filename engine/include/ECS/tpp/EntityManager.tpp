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
        auto entitySystem = dynamic_pointer_cast<IEntitySystem>(system);
        if(entitySystem && entitySystem->SubsetOf(newArcehtype))
        {
            newArcehtype.AddSystem(entitySystem);
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
    for(auto system : systems)
    {
        auto castedSystem = dynamic_pointer_cast<SystemType>(system);
        if(castedSystem)
            return castedSystem;
    }

    auto system = make_shared<SystemType>();
    systems.push_back(system);
    systems[systems.size()-1]->InternalInit(*this);
    return system;
}

template<class SystemType, class... SystemTypes>
void EntityManager::GetOrCreateSystems()
{
    GetOrCreateSystem<SystemType>();

    if constexpr (sizeof...(SystemTypes) > 0)
    {
        GetOrCreateSystems<SystemTypes...>();
    }
}

template<class TargetType, class... RequiredTypes>
int EntityManager::GetData(TargetType * targetArray)
{
    auto archetypes = GetArchetypes<RequiredTypes...>();
    auto currentIndex = 0;

    for(auto archetype : archetypes)
    {
        archetype->GetData(targetArray + currentIndex);
        currentIndex += archetype->EntityCount();
    }

    return currentIndex;
}
