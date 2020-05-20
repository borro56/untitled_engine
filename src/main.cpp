#include "../include/Components/Translation.h"
#include "../include/Components/Health.h"
#include "../include/ECS/EntityManager.h"
#include "../app/TestSystem.h"

int main ()
{

    EntityManager em;
    em.Create(Translation(Vector3(25,1,1)), Health(1));
    em.Create(Translation(Vector3(32,1,1)), Health(7));
    em.Create(Health(1), Translation(Vector3(77,1,1)) );
    em.Create(Translation(Vector3(97,1,1)) );

    auto& archetype = em.GetArchetype<Health, Translation>();
    auto& translationType = archetype.GetType<Translation>();

    TestSystem ts;
    ts.Execute(archetype.GetChunkAt(0), archetype);
}