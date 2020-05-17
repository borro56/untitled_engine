#ifndef UNTITLED_CHUNK_H
#define UNTITLED_CHUNK_H

#include "../common.h"

const int CHUNK_SIZE = 16384;

class Chunk
{
    friend class BaseComponentArray;
    friend class Archetype;

    class Archetype* archetype;
    int amount;
    byte data[CHUNK_SIZE];

public:
    template<class... Types> void AddData(Types const&... data);

    int BytesCount();
    int RemainingBytes() { return CHUNK_SIZE - BytesCount(); }
    int Count() { return amount; }

    Chunk(Archetype* archetype) { this->archetype = archetype; }

    template<class Type> Type& GetComponent(int index); //TODO: Completar esto
};

#include "Archetype.h"
#include "Chunk.tpp"

#endif