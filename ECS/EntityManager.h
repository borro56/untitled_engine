#ifndef UNTITLED_ENTITYMANAGER_H
#define UNTITLED_ENTITYMANAGER_H

#include "Entity.h"
#include <vector>

using namespace std;

class EntityManager {
public:
    class vector<class Archetype> archetypes;

public:
    template<class... Types>
    class Entity Create(Types const&... components);
};

#include "EntityManager.tpp"

#endif