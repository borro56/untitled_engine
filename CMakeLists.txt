cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        /Users/nicolasborromeo/Documents/Frameworks/glm
        /Users/nicolasborromeo/Documents/Frameworks/glfw/include
        /Users/nicolasborromeo/Documents/Frameworks/vulkansdk/macOS/include)

add_executable(untitled
        app/main.cpp
        app/include/TestSystem.h
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
        engine/include/ECS/IEntitySystem.h engine/include/Input/InputSystem.h)

target_link_libraries(untitled /Users/nicolasborromeo/Documents/Frameworks/glfw/lib-macos/libglfw.3.dylib)
target_link_libraries(untitled /Users/nicolasborromeo/Documents/Frameworks/vulkansdk/macOS/lib/libvulkan.1.2.135.dylib)


configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/engine/shaders/vert.spv
        ${CMAKE_CURRENT_BINARY_DIR}/shaders/vert.spv
        COPYONLY)

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/engine/shaders/frag.spv
        ${CMAKE_CURRENT_BINARY_DIR}/shaders/frag.spv
        COPYONLY)