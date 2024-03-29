#include "../engine/include/ECS/Components/Translation.h"
#include "../engine/include/Render/RenderSystem.h"
#include "../engine/include/Core/TimeSystem.h"
#include "include/PlayerMovementSystem.h"
#include "include/Components/Speed.h"
#include "include/CollisionSystem.h"
#include "include/Components/Player.h"
#include "include/Components/Enemy.h"
#include "include/MoveForwardSystem.h"
#include "include/TimedDeleteSystem.h"

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
//PERFORMANCE
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
//Remove non exposed headers
//Analizar uso de mutex en render system
//single large uniform buffer
//entity version system
//normalize all getters and setters
//Reuse entity ids
//implement circular buffers for uniforms regeneration

int main()
{
    EntityManager em;
    em.GetOrCreateSystems<
            MoveForwardSystem,
            TimeSystem,
            CollisionSystem, // <----
            PlayerMovementSystem,
            TimedDeleteSystem>();

    auto renderSystem = em.GetOrCreateSystem<RenderSystem>();
    auto inputSystem = em.GetOrCreateSystem<InputSystem>();

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

    em.Create(  EnemyTag(),
                Translation(Vector3(0,1.5,0)),
                Scale(),
                Rotation(),
                Renderable(mesh2, pipeline));

    em.Start();

    return EXIT_SUCCESS;
}