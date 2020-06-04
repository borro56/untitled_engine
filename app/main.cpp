#include "../engine/include/ECS/Components/Translation.h"
#include "../engine/include/Render/RenderSystem.h"
#include "../engine/include/Core/TimeSystem.h"
#include "include/TestSystem.h"
#include "include/Components/Speed.h"
#include "../engine/include/Input/InputSystem.h"
#include "include/CollisionSystem.h"

const std::vector<Vertex> vertices = {
        {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
        {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
        {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}
};

const std::vector<uint16_t> indices = { 0, 1, 2, 2, 3, 0 };

const std::vector<Vertex> vertices2 = {
        {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
        {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}
};

const std::vector<uint16_t> indices2 = { 0, 1, 2 };

//Tasks:
//Implement custom shaders
//Implement Materials
//Implement frustum culling
//Implement cameras as an object
//Fix TODOs
//Reapply const correctness
//Recheck memory usage and leaks (smart pointers)
//Fix chunks for single objects (Time EntitySystem)
//Look for where equivalent for templates
//Check why GetOrCreateSystems wont compile

int main()
{
    EntityManager em;
    em.GetOrCreateSystems<TestSystem,TimeSystem, CollisionSystem>();

    auto renderSystem = em.GetOrCreateSystem<RenderSystem>();
    auto mesh = renderSystem->CreateMesh(vertices, indices);
    auto mesh2 = renderSystem->CreateMesh(vertices2, indices2);
    auto pipeline = renderSystem->CreateGraphicsPipeline("shaders/vert.spv", "shaders/frag.spv");

    auto inputSystem = em.GetOrCreateSystem<InputSystem>();
    inputSystem->SetWindow(renderSystem->GetWindow());

    em.Create(  Translation(Vector3(0,0,0)),
                Scale(),
                Rotation(),
                Renderable(0, mesh, pipeline),
                Speed(0.1f)); //TODO: Auto assign renderId

    em.Create(  Translation(Vector3(1,0,0)),
                Scale(),
                Rotation(Vector3(0,0,45)),
                Renderable(1, mesh2, pipeline),
                Speed(0.01f));

    em.Create(  Translation(Vector3(-1,-2,0)),
                Scale(Vector3(0.5f,0.5f,0.5f)),
                Rotation(Vector3(0,0,15)),
                Renderable(2, mesh, pipeline),
                Speed(0.05f));

    em.Start();

    return EXIT_SUCCESS;
}