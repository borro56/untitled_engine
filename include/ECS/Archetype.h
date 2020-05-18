#ifndef UNTITLED_ARCHETYPE_H
#define UNTITLED_ARCHETYPE_H

#include "../common.h"

class Chunk;
class BaseComponentType;
template<class Type> class ComponentType;

class Archetype
{
public:
    template <class... Types> static Archetype Create();

private:
    int entitySize = 0;
    vector<BaseComponentType> componentTypes;
    vector<shared_ptr<Chunk>> chunks;

public:
    int ChunkCount() { return chunks.size(); }
    Chunk& GetChunkAt(int i) { return *chunks[i]; }
    int EntitySize() { return entitySize; }

private:
    shared_ptr<Chunk> GetChunk();
    template<class Type, class... Types> void AddType();
    template<class Type, class... Types> bool HasTypesRecursive();
    Archetype() { }

public:
    template<class... Types> void AddEntity(Types const&... components);
    template<class... Types> bool HasTypes();
    template<class Type> ComponentType<Type>& GetType();
};

#include "ComponentType.h"
#include "Chunk.h"
#include "tpp/Archetype.tpp"

#endif
