#ifndef UNTITLED_PLAYERMOVEMENTSYSTEM_H
#define UNTITLED_PLAYERMOVEMENTSYSTEM_H

#include "../../engine/include/ECS/EntitySystem.h"
#include "../../engine/include/ECS/Components/Rotation.h"
#include "Components/Health.h"
#include "Components/Speed.h"
#include "../../engine/include/Input/InputSystem.h"
#include "Components/Player.h"
#include "Components/MoveForwardTag.h"

class PlayerMovementSystem : public EntitySystem<Translation, Speed, Renderable, PlayerTag>
{
    shared_ptr<TimeSystem> time;
    shared_ptr<InputSystem> input;
    bool leftPressed;
    bool rightPressed;
    bool spacePressed;
    float deltaTime;

protected:
    void Initialize() override
    {
        time = entityManager->GetOrCreateSystem<TimeSystem>();
        input = entityManager->GetOrCreateSystem<InputSystem>();
    }

    void PrepareFrame() override
    {
        leftPressed = input->GetKey(GLFW_KEY_A);
        rightPressed = input->GetKey(GLFW_KEY_D);
        spacePressed = input->GetKey(GLFW_KEY_SPACE);
        deltaTime = time->GetDeltaTime();
    }

    void InternalExecute(Translation& rot, Speed& speed, Renderable& render, PlayerTag&) override
    {
        if(leftPressed)
            rot.value.x -= speed.value * deltaTime;

        if(rightPressed)
            rot.value.x += speed.value * deltaTime;

        if(spacePressed)
        {
            //TODO: Make this thread safe
            entityManager->Create(  Translation(Vector3(0,-1.5,0)),
                        Scale(),
                        Rotation(),
                        render,
                        Speed(2),
                        MoveForwardTag());
        }
    }
};

#endif