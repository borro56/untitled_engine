#include "../../include/ECS/ComponentType.h"
#include "../../include/ECS/Chunk.h"

byte* Chunk::GetArrayBase(const BaseComponentType &type)
{
    return this->data + type.ChunkOffset();
}