#ifndef UNTITLED_ARCHETYPE_H
#define UNTITLED_ARCHETYPE_H

#include "../common.h"

class Chunk;
class BaseComponentType;
template<class Type> class ComponentType;

class Archetype
{

public:
    template <class... Types> static Archetype Create(class EntityManager& manager);

private:
    int entitySize = 0;
    EntityManager& entityManager;
    vector<BaseComponentType> componentTypes;
    vector<shared_ptr<Chunk>> chunks;
    vector<class ISystem*> systems; //TODO: Replace this with shared_ptr

public:
    int ChunkCount() const { return chunks.size(); }
    int EntitySize() const { return entitySize; }
    Chunk& GetChunkAt(const int i) const { return *chunks[i]; }
    void AddSystem(ISystem* system) { systems.push_back(system); } //TODO: Make this private and friend

private:
    Chunk& GetOrCreateChunk();
    template<class Type, class... Types> void AddType();
    Archetype(EntityManager& entityManager);

public:
    template<class... Types> void AddEntity(Types const&... components);
    template<class... Types> bool HasTypes() const;
    template<class Type, class... Types> bool ContainsTypes() const;
    template<class Type> const ComponentType<Type>& GetType() const;
    void ExecuteSystems();

};

//TODO: Remove non exposed headers
#include "ComponentType.h"
#include "Chunk.h"
#include "tpp/Archetype.tpp"

#endif