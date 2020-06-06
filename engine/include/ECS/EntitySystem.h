#ifndef UNTITLED_ENTITYSYSTEM_H
#define UNTITLED_ENTITYSYSTEM_H

#include "System.h"
#include "IEntitySystem.h"

template<class... Types>
class EntitySystem : public System, public IEntitySystem
{
    void InternalExecuteArray(class Chunk& chunk, Types*... types);

protected:
    virtual void Initialize() override;
    virtual void InternalExecute(Types&... types) = 0;

public:
    vector<Archetype*> GetArchetypes();
    bool SubsetOf(class Archetype& archetype) override;
    void Execute(class Archetype& archetype, Chunk& chunk) override;
};

#include "ComponentType.h"
#include "Chunk.h"
#include "Archetype.h"
#include "tpp/EntitySystem.tpp"

#endif