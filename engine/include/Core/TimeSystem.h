#ifndef UNTITLED_TIMESYSTEM_H
#define UNTITLED_TIMESYSTEM_H

#include "../ECS/EntitySystem.h"

class TimeSystem : public System
{
    float time = 0;
    float deltaTime = 0;

protected:
    void PrepareFrame() override;

public:
    float GetTime();
    float GetDeltaTime();
};

#endif