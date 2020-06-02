//
// Created by Nicolas Borromeo on 01/06/2020.
//

#ifndef UNTITLED_TIMESYSTEM_H
#define UNTITLED_TIMESYSTEM_H


#include "../ECS/System.h"
#include "Time.h"

class TimeSystem : public System<Time>
{
    Time* timeReference;

protected:
    void InternalExecute(Time& time) override;
    void InternalInit() override;

public:
    float GetTime();
    float GetDeltaTime();
};

#endif