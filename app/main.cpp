#include "../engine/include/ECS/Components/Translation.h"
#include "include/Components/Speed.h"
#include "../engine/include/ECS/EntityManager.h"
#include "../engine/include/Render/RenderSystem.h"
#include "include/TestSystem.h"

int main()
{
    EntityManager em;

    em.Create(  Rotation(Vector3()),
                Renderable(0),
                Speed(0.1f)); //TODO: Auto assign renderId

    em.Create(  Rotation(Vector3(0,0,45)),
                Renderable(1),
                Speed(0.01f));

    em.Create(  Rotation(Vector3(0,0,45)),
                Renderable(2),
                Speed(0.05f));

    em.GetOrCreateSystem<TestSystem>();
    em.GetOrCreateSystem<RenderSystem>();

    em.Start();

    return EXIT_SUCCESS;
}