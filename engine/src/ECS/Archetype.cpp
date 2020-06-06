#include "../../include/ECS/Archetype.h"
#include "../../include/ECS/EntitySystem.h"

Chunk& Archetype::GetOrCreateChunk()
{
    for(auto chunk : chunks)
    {
        auto chunkBytes = EntitySize() * chunk->amount;
        auto remainingBytes = CHUNK_SIZE - chunkBytes;

        if(remainingBytes > entitySize)
        {
            return *chunk;
        }
    }

    auto chunk = make_shared<Chunk>();
    chunk->index = chunks.size();
    chunks.push_back(chunk);
    return *chunk;
}

Archetype::Archetype(EntityManager& entityManager) : entityManager(entityManager)
{
}

void Archetype::ExecuteSystems(vector<class SystemThread*>& vector) //TODO: Use shared_ptr
{
    for (int i = 0; i < activeChunksAmount; ++i)
    {
        vector.push_back(new SystemThread(*chunks[i], *this));
        //ExecuteSystem(*chunk);
    }
}


void Archetype::ExecuteSystem(Chunk& chunk)
{
    for(auto system : systems) //TODO: Check why this executes twice
    {
        system->Execute(*this, chunk);
    }
}


void Archetype::ActivateNewData()
{
    activeChunksAmount = chunks.size();
    for(auto chunk : chunks)
    {
        chunk->ActivateNewData();
    }
}