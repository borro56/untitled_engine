#ifndef UNTITLED_COMPONENTTYPE_H
#define UNTITLED_COMPONENTTYPE_H


class BaseComponentType
{
    friend class Archetype;
    friend class Chunk;

    size_t componentHash;
    size_t componentSize;
    size_t chunkOffset;

protected:
    virtual void dummy() { } //TODO: Check why this is neccesary

    BaseComponentType(size_t componentHash, size_t componentSize) :
            componentHash(componentHash),
            componentSize(componentSize) { }

public:
    size_t ComponentSize() { return componentSize; }
    size_t ComponentHash() { return componentHash; }

    void ChunkOffset(size_t chunkOffset) { this->chunkOffset = chunkOffset; } //TODO: Buscar otra forma de hacer propiedades
};

template<class Type>
class ComponentType : public BaseComponentType
{
public:
    ComponentType() : BaseComponentType(typeHash<Type>(), sizeof(Type)) {}
};

#include "Chunk.h"
#include "ComponentType.tpp" //TODO: Search better way to separate template definition

#endif