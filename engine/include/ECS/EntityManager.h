#ifndef UNTITLED_ENTITYMANAGER_H
#define UNTITLED_ENTITYMANAGER_H

#include "../common.h"

using namespace std;

class EntityManager {
    vector<class ISystem*> systems;
    vector<class Archetype> archetypes;
    template <class... Types> Archetype& GetOrCreateArchetype();

public:
    template<class... Types> vector<Archetype*> GetArchetypes();

    template<class... Types> const class Entity Create(Types const&... components);
    template<class SystemType> SystemType* GetOrCreateSystem();
    void ExecuteSystems();
};

#include "Archetype.h"
#include "Entity.h"
#include "SystemThread.h"
#include "System.h"
#include "tpp/EntityManager.tpp"

#endif