#ifndef UNTITLED_CHUNK_H
#define UNTITLED_CHUNK_H

#include "../common.h"

const int CHUNK_SIZE = 16384;

class Archetype;
template<class Type> class ComponentType;


class Chunk
{
    friend class Archetype;

    int amount;
    byte data[CHUNK_SIZE];

    template<class... Types> void AddData(Archetype& archetype, Types const&... rest);
    template<class Type, class... Types> void AddDataRecursive(Archetype& archetype, Type const& data, Types const&... rest);

public:
    int Count() const { return amount; }

    template<class Type> Type* GetArray(const ComponentType<Type>& type);
};

#include "Archetype.h"
#include "ComponentType.h"
#include "tpp/Chunk.tpp"

#endif