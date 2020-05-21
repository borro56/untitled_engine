#include "../../engine/include/Components/Translation.h"
#include "../../engine/include/Components/Health.h"
#include "../../engine/include/ECS/EntityManager.h"
#include "../include/TestSystem.h"

int main ()
{
    EntityManager em;
    em.Create(Translation(Vector3(25,1,1)), Health(1));
    em.Create(Translation(Vector3(32,1,1)), Health(7));
    em.Create(Health(1), Translation(Vector3(77,1,1)) );
    em.Create(Translation(Vector3(97,1,1)) );

    TestSystem ts(em);
    ts.Execute();
}