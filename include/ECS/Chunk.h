#ifndef UNTITLED_CHUNK_H
#define UNTITLED_CHUNK_H

#include "../common.h"

const int CHUNK_SIZE = 16384;

class Archetype;
template<class Type> class ComponentType;


class Chunk
{
    friend class Archetype;

    class Archetype& archetype;
    int amount;
    byte data[CHUNK_SIZE];

    template<class... Types> void AddData(Types const&... rest);
    template<class Type, class... Types> void AddDataRecursive(Type const& data, Types const&... rest);

public:
    int BytesCount();
    int RemainingBytes() { return CHUNK_SIZE - BytesCount(); }
    int Count() { return amount; }

    Chunk(Archetype& archetype) : archetype(archetype) { }

    template<class Type> Type& GetAt(ComponentType<Type>& type, int i);
};

#include "Archetype.h"
#include "ComponentType.h"
#include "tpp/Chunk.tpp"

#endif