#ifndef UNTITLED_COLLISIONSYSTEM_H
#define UNTITLED_COLLISIONSYSTEM_H

#include "../../engine/include/ECS/EntitySystem.h"
#include "../../engine/include/ECS/Components/Rotation.h"
#include "Components/Health.h"
#include "Components/Speed.h"
#include "../../engine/include/Input/InputSystem.h"
#include "../../engine/include/ECS/Components/Translation.h"

class CollisionSystem : public EntitySystem<struct EnemyTag, Translation>
{
    int amount;
    Translation translations[256];

protected:
    void Initialize() override
    {

    }

    void PrepareFrame() override
    {
        amount = entityManager->GetData<Translation, MoveForwardTag>(translations, 256); //TODO: Solve this limitation
    }

    void InternalExecute(Entity entity, EnemyTag& tag, Translation& pos) override
    {
        for (int i = 0; i < amount; ++i)
        {
            auto& otherTranslation = translations[i];
            auto distance = otherTranslation.value.Distance(pos.value);

            if(distance > 0.01f && distance < 0.5f)
            {
                entityManager->Delete(entity);
            }
        }
    }
};
#endif
