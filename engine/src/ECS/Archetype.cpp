#include "../../include/ECS/Archetype.h"

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