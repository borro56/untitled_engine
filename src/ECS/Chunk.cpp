#include "../../include/ECS/Chunk.h"

int Chunk::BytesCount() const { return archetype.EntitySize() * amount; }