#ifndef UNTITLED_ARCHETYPE_H
#define UNTITLED_ARCHETYPE_H

#include "../common.h"

template<class Type> class ComponentType;

class Archetype
{

public:
    template <class... Types> static Archetype Create();

private:
    int entitySize = 0;
    vector<class BaseComponentType> componentTypes; //TODO: See if its worth making those pointers
    vector<class Chunk*> chunks;

public:
    const vector<Chunk*>& Chunks() const { return chunks; } //TODO: Ver porque se puede mutar
    int EntitySize() { return EntitySize(); }

private:
    Chunk* GetChunk();
    template<class Type, class... Types> void AddType();
    template<class Type, class... Types> bool HasTypesRecursive();
    Archetype() { }

public:
    template<class... Types> void AddEntity(Types const&... components);
    template<class... Types> bool HasTypes();
    template<class Type> ComponentType<Type>& GetType();
};

#include "ComponentType.h"
#include "Chunk.h"
#include "Archetype.tpp"

#endif
