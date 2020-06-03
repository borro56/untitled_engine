//
// Created by Nicolas Borromeo on 03/06/2020.
//

#ifndef UNTITLED_IENTITYSYSTEM_H
#define UNTITLED_IENTITYSYSTEM_H

#include "../common.h"

class IEntitySystem : public enable_shared_from_this<IEntitySystem>
{
public:
    virtual bool SubsetOf(class Archetype& archetype) = 0;
    virtual void Execute(class Archetype& archetype, class Chunk& chunk) = 0;
};

#endif