#ifndef UNTITLED_TESTSYSTEM_H
#define UNTITLED_TESTSYSTEM_H

#include "../../engine/include/ECS/EntitySystem.h"
#include "../../engine/include/ECS/Components/Rotation.h"
#include "Components/Health.h"
#include "Components/Speed.h"

class TestSystem : public EntitySystem<Rotation, Speed>
{
    shared_ptr<TimeSystem> time;

protected:
    void InternalInit() override
    {
        time = entityManager->GetOrCreateSystem<TimeSystem>();
    }

    void InternalExecute(Rotation& rot, Speed& speed) override
    {
        rot.value.z += speed.value * time->GetDeltaTime();
    }
};


#endif