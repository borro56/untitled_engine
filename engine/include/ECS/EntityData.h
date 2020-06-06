#ifndef UNTITLED_ENTITYDATA_H
#define UNTITLED_ENTITYDATA_H

struct EntityData
{
    short archetypeIndex;
    short chunkIndex;
    short entityIndex;

    bool operator<(const EntityData& e2) const
    {
        return  archetypeIndex < e2.archetypeIndex &&
                chunkIndex < e2.chunkIndex &&
                entityIndex < e2.entityIndex;
    }
};

#endif