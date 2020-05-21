#ifndef UNTITLED_SYSTEM_H
#define UNTITLED_SYSTEM_H

class ISystem
{
    friend class EntityManager;

protected:
    EntityManager& entityManager;

    ISystem(EntityManager& entityManager) : entityManager(entityManager) {  }

public:
    //virtual void Execute() = 0;
    virtual void Execute(Archetype& archetype, Chunk& chunk) = 0;

};

template<class... Types>
class System : public ISystem
{
    void InternalExecuteArray(Chunk& chunk, Types*... types);

protected:
    virtual void InternalExecute(Types&... types) = 0;

    System(EntityManager& entityManager);

public:
    void Execute(Archetype& archetype,Chunk& chunk) override;
};

#include "Chunk.h"
#include "Archetype.h"
#include "ComponentType.h"
#include "EntityManager.h"
#include "tpp/System.tpp"

#endif