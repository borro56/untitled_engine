#include <iostream>
#include "Components/Translation.h"
#include "Components/Health.h"
#include "ECS/EntityManager.h"

int main()
{
    EntityManager em;
    auto en1 = em.Create(Translation(Vector3(25,1,1)), Health(1));
    //auto en2 = em.Create(Health(), Translation());
    cout << *(float*)(em.archetypes[0].chunks[0]->data);
}