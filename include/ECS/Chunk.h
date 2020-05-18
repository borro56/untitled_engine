#ifndef UNTITLED_CHUNK_H
#define UNTITLED_CHUNK_H

#include "../common.h"

const int CHUNK_SIZE = 16384;

class Archetype;
template<class Type> class ComponentType;

class Chunk
{
    friend class Archetype;

    class Archetype* archetype;
    int amount;
    byte data[CHUNK_SIZE];

    template<class... Types> void AddData(Types const&... rest);
    template<class Type, class... Types> void AddDataRecursive(Type const& data, Types const&... rest);

public:
    int BytesCount();
    int RemainingBytes() { return CHUNK_SIZE - BytesCount(); }
    int Count() { return amount; }

    Chunk(Archetype* archetype) { this->archetype = archetype; }

    template<class Type> Type* GetArray(ComponentType<Type>& type);
};

#include "Archetype.h"
#include "ComponentType.h"
#include "Chunk.tpp"

#endif