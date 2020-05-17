#ifndef UNTITLED_COMPONENTARRAY_H
#define UNTITLED_COMPONENTARRAY_H

#include "../common.h"

class BaseComponentArray
{
    byte* data;
    size_t componentHash;
    size_t componentSize;
    size_t chunkOffset;

public:
    size_t ComponentSize() { return componentSize; }
    size_t ComponentHash() { return componentHash; }

    BaseComponentArray(size_t componentHash, size_t componentSize)
    {
        this->componentHash = componentHash;
        this->componentSize = componentSize;
    }

    void ChunkOffset(size_t chunkOffset) { this->chunkOffset = chunkOffset; }
    void SetChunk(class Chunk& chunk);
    void* GetAt(int index) { return data + index * componentSize; }

    virtual void dummy() { } //TODO: Investigate why this
};

template<class Type>
class ComponentArray : public BaseComponentArray
{
public:
    ComponentArray() : BaseComponentArray(typeid(Type).hash_code(), sizeof(Type)) { }

    template<class T> void* GetAt(int index) { return (T*)GetAt(index); }
};


#include "Chunk.h"

#endif
