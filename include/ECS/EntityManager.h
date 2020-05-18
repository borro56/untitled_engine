#ifndef UNTITLED_ENTITYMANAGER_H
#define UNTITLED_ENTITYMANAGER_H

#include "../common.h"

using namespace std;

class EntityManager {
    class vector<class Archetype> archetypes;
    template <class... Types> Archetype& GetOrCreateArchetype();

public:
    template<class... Types> class Entity Create(Types const&... components);
    template<class... Types> Archetype& GetArchetype();
};

#include "Archetype.h"
#include "Entity.h"
#include "tpp/EntityManager.tpp"

#endif