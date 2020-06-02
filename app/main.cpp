#include "../engine/include/ECS/Components/Translation.h"
#include "../engine/include/Render/RenderSystem.h"
#include "../engine/include/Core/TimeSystem.h"
#include "include/TestSystem.h"
#include "include/Components/Speed.h"

const std::vector<Vertex> vertices = {
        {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
        {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
        {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}
};

const std::vector<uint16_t> indices = {
        0, 1, 2, 2, 3, 0
};


int main()
{
    EntityManager em;
    em.GetOrCreateSystem<TestSystem>();
    em.GetOrCreateSystem<TimeSystem>();
    auto renderSystem = em.GetOrCreateSystem<RenderSystem>();
    auto mesh = renderSystem->CreateMesh(vertices, indices);

    em.Create(  Translation(),
                Scale(),
                Rotation(),
                Renderable(0, mesh),
                Speed(0.1f)); //TODO: Auto assign renderId

    em.Create(  Translation(Vector3(1,0,0)),
                Scale(),
                Rotation(Vector3(0,0,45)),
                Renderable(1, mesh),
                Speed(0.01f));

    em.Create(  Translation(Vector3(-1,0,0)),
                Scale(Vector3(0.5f,0.5f,0.5f)),
                Rotation(Vector3(0,0,15)),
                Renderable(2, mesh),
                Speed(0.05f));

    em.Start();

    return EXIT_SUCCESS;
}