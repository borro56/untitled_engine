#ifndef UNTITLED_SYSTEM_H
#define UNTITLED_SYSTEM_H

#include "../common.h"

class EntityManager;

class System
{
    friend EntityManager;
    void InternalInit(EntityManager& entityManager); //TODO: Review internalinit vs constructor

protected:
    EntityManager* entityManager;

    virtual void Initialize() { }
    virtual void PrepareFrame() { }
    virtual void FinishFrame() { }
};

#endif