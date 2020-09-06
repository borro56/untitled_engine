#ifndef UNTITLED_CHUNK_H
#define UNTITLED_CHUNK_H

#include "../common.h"

const int CHUNK_SIZE = 16384;
//const int CHUNK_SIZE = 160;

class Archetype;
template<class Type> class ComponentType;

class Chunk
{
    friend class Archetype;
    friend class EntityManager;

private:
    int archetypeIndex = -1;
    int index = -1;
    int amount = 0;
    int activeAmount = 0;
    byte data[CHUNK_SIZE];

    template<class... Types> void AddData(Archetype& archetype, Types const&... rest);
    template<class Type, class... Types> void AddDataRecursive(Archetype& archetype, Type const& data, Types const&... rest);

    void ActivateNewData() { activeAmount = amount; }

    byte* GetArrayBase(const BaseComponentType& type);

public:
    int Count() const { return activeAmount; }
    int GetIndex() { return index; }
    int GetArchetypeIndex() { return archetypeIndex; }

    template<class Type> Type* GetArray(const ComponentType<Type>& type) const;
};

#include "Archetype.h"
#include "ComponentType.h"
#include "tpp/Chunk.tpp"

#endif