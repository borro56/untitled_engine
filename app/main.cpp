#include "../engine/include/ECS/Components/Translation.h"
#include "include/Components/Speed.h"
#include "../engine/include/ECS/EntityManager.h"
#include "../engine/include/Render/RenderSystem.h"
#include "include/TestSystem.h"

int main()
{
    EntityManager em;

    em.Create(  Translation(),
                Scale(),
                Rotation(),
                Renderable(0),
                Speed(0.1f)); //TODO: Auto assign renderId

    em.Create(  Translation(Vector3(1,0,0)),
                Scale(),
                Rotation(Vector3(0,0,45)),
                Renderable(1),
                Speed(0.01f));

    em.Create(  Translation(Vector3(-1,0,0)),
                Scale(Vector3(0.5f,0.5f,0.5f)),
                Rotation(Vector3(0,0,15)),
                Renderable(2),
                Speed(0.05f));

    em.GetOrCreateSystem<TestSystem>();
    em.GetOrCreateSystem<RenderSystem>();

    em.Start();

    return EXIT_SUCCESS;
}