#include "../engine/include/ECS/Components/Translation.h"
#include "../engine/include/Render/RenderSystem.h"
#include "../engine/include/Core/TimeSystem.h"
#include "include/PlayerMovementSystem.h"
#include "include/Components/Speed.h"
#include "../engine/include/Input/InputSystem.h"
#include "include/CollisionSystem.h"
#include "include/Components/Player.h"

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
        {{0.0f, 0.5f}, {0.0f, 0.0f, 1.0f}}
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
//Implement tag components concept
//define an coordinate system
//one thread per core

int main()
{
    EntityManager em;
    em.GetOrCreateSystems<PlayerMovementSystem,TimeSystem, CollisionSystem>();
    auto renderSystem = em.GetOrCreateSystem<RenderSystem>();
    auto inputSystem = em.GetOrCreateSystem<InputSystem>();

    auto mesh = renderSystem->CreateMesh(vertices, indices);
    auto mesh2 = renderSystem->CreateMesh(vertices2, indices2);
    auto pipeline = renderSystem->CreateGraphicsPipeline("shaders/vert.spv", "shaders/frag.spv");
    renderSystem->SetCameraPosition(Vector3(0,-4,4));

    inputSystem->SetWindow(renderSystem->GetWindow());

    em.Create(  PlayerTag(),
                Translation(Vector3(0,-1.5,0)),
                Scale(),
                Rotation(),
                Renderable(mesh2, pipeline),
                Speed(2));

    em.Start();

    return EXIT_SUCCESS;
}