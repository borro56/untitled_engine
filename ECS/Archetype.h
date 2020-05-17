#ifndef UNTITLED_ARCHETYPE_H
#define UNTITLED_ARCHETYPE_H

#include <cstddef>
#include <vector>

using namespace std;

class Archetype
{
    friend class Chunk;

    int entitySize = 0;
    vector<class ComponentType> componentTypes; //TODO: See if its worth making those pointers
    vector<class Chunk*> chunks;

    Chunk* GetChunk();
    template<class Type, class... Types> void AddType();
    template<class Type, class... Types> bool HasTypesRecursive();

    Archetype() { }

public:
    const vector<Chunk*>& Chunks() const { return chunks; } //TODO: Ver porque se puede mutar

    template<class... Types> void AddEntity(Types const&... components);

    template<class Type> ComponentType* GetType();


    template <class... Types> static Archetype Create();

    template<class... Types> bool HasTypes();
};

#include "Chunk.h"
#include "ComponentType.h"
#include "Archetype.tpp"

#endif
