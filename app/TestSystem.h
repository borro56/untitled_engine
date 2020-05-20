#ifndef UNTITLED_TESTSYSTEM_H
#define UNTITLED_TESTSYSTEM_H

#include "../include/ECS/System.h"
#include "../include/Components/Translation.h"
#include "../include/Components/Health.h"

class TestSystem : public System<Translation, Health>
{
protected:
    void InternalExecute(Translation& a, Health& b) override
    {
        cout << a.value.x << ' ' << b.value << ' ';
    }
};


#endif