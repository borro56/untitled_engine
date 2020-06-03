//
// Created by Nicolas Borromeo on 01/06/2020.
//

#ifndef UNTITLED_TIMESYSTEM_H
#define UNTITLED_TIMESYSTEM_H


#include "../ECS/EntitySystem.h"

class TimeSystem : public EntitySystem<bool>
{
    float time = 0;
    float deltaTime = 0;

protected:
    void InternalExecute(bool& time) override {}
    void PrepareFrame() override;

public:
    float GetTime();
    float GetDeltaTime();
};

#endif