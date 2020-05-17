

#include "ComponentArray.h"

void BaseComponentArray::SetChunk(class Chunk& chunk)
{
    this->data = chunk.data + chunkOffset;
}