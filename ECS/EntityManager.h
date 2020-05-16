#ifndef UNTITLED_ENTITYMANAGER_H
#define UNTITLED_ENTITYMANAGER_H

#include "Entity.h"
#include "Archetype.h"
#include <vector>

using namespace std;

class EntityManager {
    class vector<Archetype> archetypes;
    template <class... Types> Archetype* GetOrCreateArchetype();

public:
    template<class... Types> class Entity Create(Types const&... components);
    template<class... Types> Archetype* GetArchetype();
};

#include "EntityManager.tpp"

#endif