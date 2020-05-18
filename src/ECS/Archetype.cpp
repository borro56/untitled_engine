#include "../../include/ECS/Archetype.h"

shared_ptr<Chunk> Archetype::GetChunk()
{
    for(auto chunk : chunks)
    {
        if(chunk->RemainingBytes() > entitySize)
        {
            return chunk;
        }
    }

    auto chunk = make_shared<Chunk>(*this);
    chunks.push_back(chunk);
    return chunk;
}