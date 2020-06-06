#ifndef UNTITLED_ENTITYMANAGER_H
#define UNTITLED_ENTITYMANAGER_H

#include "../common.h"
#include "EntityData.h"
#include "Entity.h"

using namespace std;

class Archetype;
class System;

class EntityManager {

    mutex createdEntititesMutex;

    int createdEntitites = 0;
    bool running;

    mutex entitiesToDeleteMutex;

    vector<int> entitiesToDelete;

    map<int, EntityData> entityMap;
    map<EntityData, int> entityDataMap;

    vector<Archetype> newArchetypes;
    vector<shared_ptr<System>> systems;
    vector<Archetype> archetypes;
    template <class... Types> Archetype& GetOrCreateArchetype();
    void ActivateArchetypes();
    void DeleteEntities();

public:
    template<class... Types> vector<Archetype*> GetArchetypes();
    template<class... Types> const class Entity Create(Types const&... components);
    void Delete(Entity entity);

    template<class TargetType, class... RequiredTypes> int GetData(TargetType* targetArray);

    template<class SystemType> shared_ptr<SystemType> GetOrCreateSystem();
    template<class SystemType, class... SystemTypes> void GetOrCreateSystems();
    void ExecuteSystems();
    void Stop();
    void Start();

    Entity GetEntity(EntityData& data) { return entityDataMap[data]; }
};



#include "Archetype.h"
#include "Entity.h"
#include "SystemThread.h"
#include "EntitySystem.h"
#include "tpp/EntityManager.tpp"

#endif