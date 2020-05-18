#include "../include/Components/Translation.h"
#include "../include/Components/Health.h"
#include "../include/ECS/EntityManager.h"

//TODO: Apply const correctness everywhere
int main()
{
    EntityManager em;
    em.Create(Translation(Vector3(25,1,1)), Health(1));
    em.Create(Translation(Vector3(32,1,1)), Health(1));
    em.Create(Health(1), Translation(Vector3(77,1,1)) );
    em.Create(Translation(Vector3(97,1,1)) );

    auto& archetype = em.GetArchetype<Health, Translation>();
    auto& translationType = archetype.GetType<Translation>();

    for (int j = 0; j < archetype.ChunkCount(); ++j)
    {
        auto& chunk = archetype.GetChunkAt(j);
        auto array = chunk.GetArray(translationType);

        for (int i = 0; i < chunk.Count(); ++i)
        {
            cout << array[i].value.x;
        }
    }

    return 0;
}