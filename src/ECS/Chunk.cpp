//
// Created by Nicolas Borromeo on 17/05/2020.
//

#include "../../include/ECS/Chunk.h"

int Chunk::BytesCount() { return archetype->entitySize * amount; }