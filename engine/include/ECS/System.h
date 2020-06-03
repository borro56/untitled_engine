#ifndef UNTITLED_SYSTEM_H
#define UNTITLED_SYSTEM_H

#include "../common.h"

class System
{
    friend class EntityManager;

protected:
    class EntityManager* entityManager;

    virtual void InternalInit() { };
    virtual void Init(class EntityManager& entityManager);

    virtual void PrepareFrame() { }
    virtual void FinishFrame() { }
};

#endif