#ifndef UNTITLED_ISYSTEM_H
#define UNTITLED_ISYSTEM_H

#include "../common.h"

class ISystem : public std::enable_shared_from_this<ISystem>
{
    friend class EntityManager;

protected:
    virtual void InternalInit() { };
    virtual void Init(class EntityManager& entityManager) = 0;
    virtual bool SubsetOf(class Archetype& archetype) = 0;

    virtual void PrepareFrame() { }
    virtual void FinishFrame() { }

public:
    virtual void Execute(class Archetype& archetype, class Chunk& chunk) = 0;
};

#endif