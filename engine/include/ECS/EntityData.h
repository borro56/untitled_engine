#ifndef UNTITLED_ENTITYDATA_H
#define UNTITLED_ENTITYDATA_H

#include "../common.h"

struct EntityData
{
    short archetypeIndex;
    short chunkIndex;
    short entityIndex;

    bool operator<(const EntityData& e2) const
    {
        return archetypeIndex < e2.archetypeIndex || chunkIndex < e2.chunkIndex || entityIndex < e2.entityIndex;
    }

    bool operator==(const EntityData& e2) const
    {
        return archetypeIndex == e2.archetypeIndex && chunkIndex == e2.chunkIndex && entityIndex == e2.entityIndex;
    }
};

namespace std {
    template <>
    struct hash<EntityData>
    {
        std::size_t operator()(const EntityData& k) const
        {
            return k.entityIndex + k.chunkIndex * 10000 + k.archetypeIndex * 10000000;
        }
    };
}

#endif
