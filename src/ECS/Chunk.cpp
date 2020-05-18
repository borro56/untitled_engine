#include "../../include/ECS/Chunk.h"

int Chunk::BytesCount() { return archetype.EntitySize() * amount; }