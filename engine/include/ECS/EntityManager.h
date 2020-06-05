#ifndef UNTITLED_ENTITYMANAGER_H
#define UNTITLED_ENTITYMANAGER_H

#include "../common.h"

using namespace std;

class Archetype;
class System;

class EntityManager {
    bool running;

    vector<Archetype> newArchetypes;
    vector<shared_ptr<System>> systems;
    vector<Archetype> archetypes;
    template <class... Types> Archetype& GetOrCreateArchetype();
    void ActivateArchetypes();

public:
    template<class... Types> vector<Archetype*> GetArchetypes();
    template<class... Types> const class Entity Create(Types const&... components);

    template<class TargetType, class... RequiredTypes> int GetData(TargetType* targetArray);

    template<class SystemType> shared_ptr<SystemType> GetOrCreateSystem();
    template<class SystemType, class... SystemTypes> void GetOrCreateSystems();
    void ExecuteSystems();
    void Stop();
    void Start();
};



#include "Archetype.h"
#include "Entity.h"
#include "SystemThread.h"
#include "EntitySystem.h"
#include "tpp/EntityManager.tpp"

#endif