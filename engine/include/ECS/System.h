#ifndef UNTITLED_SYSTEM_H
#define UNTITLED_SYSTEM_H

class ISystem
{
protected:
    EntityManager& entityManager;

public:
    virtual void Execute() = 0;

    ISystem(EntityManager& entityManager) : entityManager(entityManager) {  }
};

template<class... Types>
class System : public ISystem
{
    friend class EntityManager;

    void InternalExecuteArray(Chunk& chunk, Types*... types);

protected:
    virtual void InternalExecute(Types&... types) = 0;

public:
    System(EntityManager& entityManager) : ISystem(entityManager)
    {
        auto archetypes = entityManager.GetArchetypes<Types...>();
        for(auto archetype : archetypes)
        {
            archetype->AddSystem(this);
        }
    }

    void Execute() override;
};

#include "Chunk.h"
#include "Archetype.h"
#include "ComponentType.h"
#include "EntityManager.h"
#include "tpp/System.tpp"

#endif