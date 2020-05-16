#ifndef UNTITLED_ARCHETYPE_H
#define UNTITLED_ARCHETYPE_H

#include <cstddef>
#include <vector>
#include "Chunk.h"

using namespace std;

class Archetype {
    int sizeOfEntity;
    vector<size_t> typeHashes;

    Chunk* GetChunk();

public:
    vector<Chunk*> chunks;

    Archetype(vector<size_t> typeHashes, int sizeOfEntity)
    {
        this->typeHashes = typeHashes;
        this->sizeOfEntity = sizeOfEntity;
    }
    vector<size_t>& TypesHashes() { return typeHashes; }

    template<class... Types> void AddEntity(Types const&... components);
};

#include "Archetype.tpp"

#endif