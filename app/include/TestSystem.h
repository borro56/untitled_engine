#ifndef UNTITLED_TESTSYSTEM_H
#define UNTITLED_TESTSYSTEM_H

#include "../../engine/include/ECS/EntitySystem.h"
#include "../../engine/include/ECS/Components/Rotation.h"
#include "Components/Health.h"
#include "Components/Speed.h"
#include "../../engine/include/Input/InputSystem.h"

class TestSystem : public EntitySystem<Rotation, Speed>
{
    shared_ptr<TimeSystem> time;
    shared_ptr<InputSystem> input;
    bool keyPressed;
    float deltaTime;

protected:
    void Initialize() override
    {
        time = entityManager->GetOrCreateSystem<TimeSystem>();
        input = entityManager->GetOrCreateSystem<InputSystem>();
    }

    void PrepareFrame() override
    {
        keyPressed = input->GetKey(GLFW_KEY_W);
        deltaTime = time->GetDeltaTime();
    }

    void InternalExecute(Rotation& rot, Speed& speed) override
    {
        if(keyPressed)
            rot.value.z += speed.value * deltaTime;
    }
};

#endif