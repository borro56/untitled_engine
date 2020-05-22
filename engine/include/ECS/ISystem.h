#ifndef UNTITLED_ISYSTEM_H
#define UNTITLED_ISYSTEM_H

class ISystem
{
    friend class EntityManager;

    virtual void Init(class EntityManager& entityManager) = 0;

public:
    virtual void Execute(class Archetype& archetype, class Chunk& chunk) = 0;
};

#endif