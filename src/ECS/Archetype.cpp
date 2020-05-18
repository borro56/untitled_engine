#include "../../include/ECS/Archetype.h"

Chunk* Archetype::GetChunk()
{
    for(auto chunk : chunks)
    {
        if(chunk->RemainingBytes() > entitySize)
        {
            return chunk;
        }
    }

    auto chunk = new Chunk(this);
    chunks.push_back(chunk);
    return chunk;
}
