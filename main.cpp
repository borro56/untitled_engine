#include "Components/Translation.h"
#include "Components/Health.h"
#include "ECS/EntityManager.h"
#include "common.h"
#include "Components/Speed.h"

int main()
{
    EntityManager em;
    auto en1 = em.Create(Translation(Vector3(25,1,1)), Health(1));

    auto archetype = em.GetArchetype<Translation, Health>();
    auto chunks = archetype->Chunks();
    auto translationType = archetype->GetType<Translation>();

    for(auto chunk : chunks)
    {
        auto translationArray = chunk->GetArray<Translation>(*translationType);
        for (int i = 0; i < chunk->Count(); ++i)
        {
            cout << translationArray[i].value.x;
        }
    }

    return 0;
}