#include "Archetype.h"

Chunk* Archetype::GetChunk()
{
    for(auto chunk : chunks)
    {
        if(chunk->RemainingBytes() > sizeOfEntity)
        {
            return chunk;
        }
    }

    auto chunk = new Chunk(sizeOfEntity);
    chunks.push_back(chunk);
    return chunk;
}