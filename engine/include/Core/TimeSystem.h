//
// Created by Nicolas Borromeo on 01/06/2020.
//

#ifndef UNTITLED_TIMESYSTEM_H
#define UNTITLED_TIMESYSTEM_H


#include "../ECS/System.h"

class TimeSystem : public System<class Time>
{
protected:
    virtual void InternalExecute(Time& time) override;

    void InternalInit() override;
};

#include "Time.h"

#endif
