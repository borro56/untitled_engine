#ifndef UNTITLED_ARCHETYPE_H
#define UNTITLED_ARCHETYPE_H

#include <cstddef>
#include <vector>
#include "Chunk.h"

using namespace std;

class Archetype {
    int sizeOfEntity;
    vector<size_t> typeHashes;
    vector<Chunk*> chunks;

    Chunk* GetChunk();

public:
    bool HasHashes(vector<size_t>& hashes);

    template<class... Types> void AddEntity(Types const&... components);

    Archetype(vector<size_t> typeHashes, int sizeOfEntity)
    {
        this->typeHashes = typeHashes;
        this->sizeOfEntity = sizeOfEntity;
    }
};

#include "Archetype.tpp"

#endif