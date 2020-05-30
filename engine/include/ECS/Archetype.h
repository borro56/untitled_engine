#ifndef UNTITLED_ARCHETYPE_H
#define UNTITLED_ARCHETYPE_H

#include "../common.h"

class Chunk;
class BaseComponentType;
class EntityManager;
template<class Type> class ComponentType;

class Archetype
{
    friend class SystemThread;

private:
    int entityCount = 0;
    int entitySize = 0;
    EntityManager& entityManager;
    vector<BaseComponentType> componentTypes;
    vector<shared_ptr<Chunk>> chunks;
    vector<class ISystem*> systems; //TODO: Replace this with shared_ptr

    Chunk& GetOrCreateChunk();
    template<class Type, class... Types> void AddType();
    void ExecuteSystem(Chunk& chunk);

    Archetype(EntityManager& entityManager);

public:
    template <class... Types> static Archetype Create(EntityManager& manager);

    const int EntitySize() const { return entitySize; }
    const int EntityCount() const { return entityCount; }
    const int ChunkCount() const { return chunks.size(); }
    const Chunk& GetChunkAt(const int i) const { return *chunks[i]; }

    void AddSystem(ISystem* system) { systems.push_back(system); } //TODO: Make this private and friend
    template<class... Types> void AddEntity(Types const&... components);
    template<class... Types> bool HasTypes() const;
    template<class Type, class... Types> bool ContainsTypes() const;
    template<class Type> const ComponentType<Type>& GetType() const;
    void ExecuteSystems(vector<class SystemThread*>& vector);
};

//TODO: Remove non exposed headers
#include "ComponentType.h"
#include "Chunk.h"
#include "tpp/Archetype.tpp"

#endif