#ifndef UNTITLED_SYSTEM_H
#define UNTITLED_SYSTEM_H

#include <cstdio>
#include "Chunk.h"
#include "Archetype.h"
#include "ComponentType.h"
#include "EntityManager.h"

template<class... Types>
class System
{
    void InternalExecuteArray(Chunk& chunk, Types*... types);

protected:
    virtual void InternalExecute(Types&... types) = 0;

public:
    void Execute(EntityManager& entityManager);
};

#include "tpp/System.tpp"

#endif