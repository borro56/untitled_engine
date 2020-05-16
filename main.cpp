#include <iostream>
#include <vector>
#include "Components/Translation.h"
#include "Components/Health.h"
#include "ECS/EntityManager.h"


int main()
{
    EntityManager em;
    auto en = em.Create(Translation(), Health());
    auto en2 = em.Create(Translation(), Health());
}