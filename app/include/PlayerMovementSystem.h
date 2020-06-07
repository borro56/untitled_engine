#ifndef UNTITLED_PLAYERMOVEMENTSYSTEM_H
#define UNTITLED_PLAYERMOVEMENTSYSTEM_H

#include "../../engine/include/ECS/EntitySystem.h"
#include "../../engine/include/ECS/Components/Rotation.h"
#include "Components/Health.h"
#include "Components/Speed.h"
#include "../../engine/include/Input/InputSystem.h"
#include "Components/Player.h"
#include "Components/MoveForwardTag.h"
#include "Components/DeleteTime.h"

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
        spacePressed = input->GetKeyDown(GLFW_KEY_SPACE);
        deltaTime = time->GetDeltaTime();
    }

    void InternalExecute(Entity entity, Translation& translation, Speed& speed, Renderable& render, PlayerTag&) override
    {
        if(leftPressed)
            translation.value.x -= speed.value * deltaTime;

        if(rightPressed)
            translation.value.x += speed.value * deltaTime;

        if(spacePressed)
        {
            //TODO: Make this thread safe
            entityManager->Create(translation, render,
                        DeleteTime(1 + (rand() / (float)RAND_MAX) * 2),
                        Scale(Vector3(0.1f)),
                        Rotation(),
                        Speed(-2),
                        MoveForwardTag());
        }
    }
};

#endif