//
// Created by Nicolas Borromeo on 06/06/2020.
//

#ifndef UNTITLED_TIMEDDELETESYSTEM_H
#define UNTITLED_TIMEDDELETESYSTEM_H


#include "../../engine/include/Core/TimeSystem.h"
#include "../../engine/include/ECS/Components/Translation.h"
#include "../../app/include/Components/Speed.h"
#include "../../app/include/Components/MoveForwardTag.h"
#include "Components/DeleteTime.h"

class TimedDeleteSystem : public EntitySystem<DeleteTime>
{
    shared_ptr<TimeSystem> time;
    float deltaTime;

protected:
    void Initialize() override
    {
        time = System::entityManager->GetOrCreateSystem<TimeSystem>();
    }

    void PrepareFrame() override
    {
        deltaTime = time->GetDeltaTime();
    }

    void InternalExecute(Entity entity, DeleteTime& time) override
    {
        time.remainingTime -= deltaTime;
        if(time.remainingTime <= 0)
        {
            entityManager->Delete(entity);
        }
    }
};

#endif