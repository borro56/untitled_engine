#ifndef UNTITLED_ENTITYSYSTEM_H
#define UNTITLED_ENTITYSYSTEM_H

#include "System.h"
#include "IEntitySystem.h"

template<class... Types>
class EntitySystem : public System, public IEntitySystem
{
    friend class EntityManager;

    void InternalExecuteArray(class Chunk& chunk, Types*... types);

protected:
    virtual void InternalExecute(Types&... types) = 0;
    virtual void Init(class EntityManager& entityManager) override;
    bool SubsetOf(class Archetype& archetype) override;

public:
    vector<Archetype*> GetArchetypes();

    void Execute(class Archetype& archetype, Chunk& chunk) override;
};

#include "Chunk.h"
#include "Archetype.h"
#include "ComponentType.h"
#include "tpp/EntitySystem.tpp"

#endif