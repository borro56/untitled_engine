#include <iostream>
#include "Components/Translation.h"
#include "Components/Health.h"
#include "ECS/EntityManager.h"

int main()
{
    EntityManager em;
    auto en1 = em.Create(Translation(Vector3(25,1,1)), Health(1));
    auto en2 = em.Create(Health(4), Translation());
    return 0;
}