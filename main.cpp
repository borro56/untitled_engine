#include "Components/Translation.h"
#include "Components/Health.h"
#include "ECS/EntityManager.h"
#include "common.h"
#include "Components/Speed.h"

int main()
{
    EntityManager em;
    auto en1 = em.Create(Translation(Vector3(25,1,1)), Health(1));
    auto en2 = em.Create(Translation(), Health(4));
    auto en3 = em.Create(Translation(Vector3(25,1,1)), Speed(1));

    auto archetype = em.GetArchetype<Translation, Health>();
    auto chunks = archetype->Chunks();
    auto translationArray = archetype->GetComponentArray<Translation>();

    for(auto chunk : chunks)
    {
        translationArray->SetChunk(*chunk);
        for (int i = 0; i < chunk->Count(); ++i)
        {

        }
    }

    return 0;
}