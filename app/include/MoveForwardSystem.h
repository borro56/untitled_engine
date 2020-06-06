//
// Created by Nicolas Borromeo on 05/06/2020.
//

#ifndef UNTITLED_MOVEFORWARDSYSTEM_H
#define UNTITLED_MOVEFORWARDSYSTEM_H

#include "../../engine/include/Core/TimeSystem.h"
#include "../../engine/include/ECS/Components/Translation.h"
#include "../../app/include/Components/Speed.h"
#include "../../app/include/Components/MoveForwardTag.h"

class MoveForwardSystem : public EntitySystem<Translation, Speed, MoveForwardTag>
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

    void InternalExecute(Entity entity, Translation& pos, Speed& speed, MoveForwardTag&) override
    {
        pos.value.y -= speed.value * deltaTime;
    }
};

#include "../../engine/include/ECS/EntitySystem.h"
#include "../../engine/include/ECS/Components/Rotation.h"
#include "Components/Health.h"
#include "Components/Speed.h"
#include "../../engine/include/Input/InputSystem.h"
#include "Components/Player.h"

#endif