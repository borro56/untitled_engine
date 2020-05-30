#ifndef UNTITLED_ISYSTEM_H
#define UNTITLED_ISYSTEM_H

class ISystem
{
    friend class EntityManager;

protected:
    virtual void Init(class EntityManager& entityManager) = 0;
    virtual void Prepare() { }
    virtual void Finish() { }

public:
    virtual void Execute(class Archetype& archetype, class Chunk& chunk) = 0;
};

#endif