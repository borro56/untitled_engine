cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        c:/cpp/glm
        c:/cpp/glfw/include
        c:/VulkanSDK/1.2.148.1/include
        c:/cpp/mingw-std-threads)

add_executable(untitled
        app/main.cpp
        app/include/PlayerMovementSystem.h
        engine/src/ECS/Archetype.cpp
        engine/src/ECS/EntityManager.cpp
        engine/src/ECS/SystemThread.cpp
        engine/src/Input/InputSystem.cpp
        engine/src/ECS/System.cpp
        engine/include/Render/RenderSystem.h
        engine/include/Render/Renderable.h
        engine/include/Core/TimeSystem.cpp
        engine/include/Core/TimeSystem.h
        engine/include/Render/Mesh.h
        engine/include/ECS/IEntitySystem.h engine/include/Input/InputSystem.h app/include/CollisionSystem.h app/include/Components/Player.h app/include/Components/MoveForwardTag.h engine/include/ECS/EntityData.h engine/src/ECS/Chunk.cpp engine/src/ECS/EntityData.cpp app/include/Components/DeleteTime.h app/include/TimedDeleteSystem.h)

target_link_libraries(untitled c:/cpp/glfw/lib-mingw-w64/libglfw3.a)
target_link_libraries(untitled c:/VulkanSDK/1.2.148.1/lib/vulkan-1.lib)


configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/engine/shaders/vert.spv
        ${CMAKE_CURRENT_BINARY_DIR}/shaders/vert.spv
        COPYONLY)

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/engine/shaders/frag.spv
        ${CMAKE_CURRENT_BINARY_DIR}/shaders/frag.spv
        COPYONLY)