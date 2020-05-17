#ifndef UNTITLED_COMPONENTTYPE_H
#define UNTITLED_COMPONENTTYPE_H

#include "../common.h"

class ComponentType
{
    friend class Archetype;
    friend class Chunk;

    size_t componentHash;
    size_t componentSize;
    size_t chunkOffset;

    template <class Type> static ComponentType Create();

    ComponentType() { }

public:
    size_t ComponentSize() { return componentSize; }
    size_t ComponentHash() { return componentHash; }

    ComponentType(size_t componentHash, size_t componentSize) :
        componentHash(componentHash),
        componentSize(componentSize) { }

    void ChunkOffset(size_t chunkOffset) { this->chunkOffset = chunkOffset; } //TODO: Buscar otra forma de hacer propiedades
};

#include "Chunk.h"
#include "ComponentType.tpp" //TODO: Search better way to separate template definition

#endif