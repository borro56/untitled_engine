#include "../../include/ECS/Archetype.h"
#include "../../include/ECS/System.h"
#include "../../include/ECS/SystemThread.h"

Chunk& Archetype::GetOrCreateChunk()
{
    for(auto chunk : chunks)
    {
        auto chunkBytes = EntitySize() * chunk->amount;
        auto remainingBytes =  CHUNK_SIZE - chunkBytes;

        if(remainingBytes > entitySize)
        {
            return *chunk;
        }
    }

    auto chunk = make_shared<Chunk>();
    chunks.push_back(chunk);
    return *chunk;
}


Archetype::Archetype(EntityManager& entityManager) : entityManager(entityManager)
{
}

void Archetype::ExecuteSystems(vector<class SystemThread*>& vector)
{
    for(auto chunk : chunks)
    {
        vector.push_back(new SystemThread(*chunk, *this));
    }
}


void Archetype::ExecuteSystem(Chunk& chunk)
{
    for(auto system : systems)
    {
        system->Execute(*this, chunk);
    }
}