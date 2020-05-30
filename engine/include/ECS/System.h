#ifndef UNTITLED_SYSTEM_H
#define UNTITLED_SYSTEM_H

#include "ISystem.h"

template<class... Types>
class System : public ISystem
{
    friend class EntityManager;

    EntityManager* entityManager;

    void InternalExecuteArray(Chunk& chunk, Types*... types);

protected:
    virtual void InternalExecute(Types&... types) = 0;
    void Init(class EntityManager& entityManager) override ;

public:
    vector<Archetype*> GetArchetypes();

    void Execute(Archetype& archetype,Chunk& chunk) override;
};

#include "Chunk.h"
#include "Archetype.h"
#include "ComponentType.h"
#include "EntityManager.h"
#include "tpp/System.tpp"

#endif