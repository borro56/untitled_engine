#include "../../include/ECS/Archetype.h"
#include "../../include/ECS/System.h"

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

void Archetype::ExecuteSystems(vector<class SystemThread*>& vector) //TODO: Use shared_ptr
{
    for(auto chunk : chunks)
    {
        vector.push_back(new SystemThread(*chunk, *this));
        //ExecuteSystem(*chunk);
    }
}


void Archetype::ExecuteSystem(Chunk& chunk)
{
    for(auto system : systems)
    {
        system->Execute(*this, chunk);
    }
}