#ifndef UNTITLED_TESTSYSTEM_H
#define UNTITLED_TESTSYSTEM_H

#include "../../engine/include/ECS/System.h"
#include "../../engine/include/Components/Translation.h"
#include "../../engine/include/Components/Health.h"

class TestSystem : public System<Translation>
{
protected:
    void InternalExecute(Translation& a) override
    {
        cout << a.value.x << ' ';
    }
};


#endif