#ifndef UNTITLED_TESTSYSTEM_H
#define UNTITLED_TESTSYSTEM_H

#include "../../engine/include/ECS/System.h"
#include "../../engine/include/ECS/Components/Rotation.h"
#include "Components/Health.h"
#include "Components/Speed.h"

class TestSystem : public System<Rotation, Speed>
{
protected:
    void InternalExecute(Rotation& rot, Speed& speed) override
    {
        rot.value.z += speed.value;
    }
};


#endif