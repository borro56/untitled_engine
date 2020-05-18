    #include "../include/Components/Translation.h"
    #include "../include/Components/Health.h"
    #include "../include/ECS/EntityManager.h"
    #include "../include/common.h"

    int main()
    {
        EntityManager em;
        em.Create(Translation(Vector3(25,1,1)), Health(1));

        auto archetype = em.GetArchetype<Health, Translation>();
        auto chunks = archetype->Chunks();
        auto translationType = archetype->GetType<Translation>();

        for(auto chunk : chunks)
        {
            auto translationArray = chunk->GetArray(*translationType);
            for (int i = 0; i < chunk->Count(); ++i)
            {
                cout << translationArray[i].value.x;
            }
        }

        return 0;
    }