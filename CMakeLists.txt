cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        /Users/nicolasborromeo/Documents/Frameworks/glm
        /Users/nicolasborromeo/Documents/Frameworks/glfw/include
        /Users/nicolasborromeo/Documents/Frameworks/vulkansdk/macOS/include)

add_executable(untitled
        app/main.cpp
        engine/src/ECS/Archetype.cpp
        engine/src/ECS/EntityManager.cpp
        engine/src/ECS/SystemThread.cpp
        engine/src/ECS/ISystem.cpp)

target_link_libraries(untitled /Users/nicolasborromeo/Documents/Frameworks/glfw/lib-macos/libglfw.3.dylib)
target_link_libraries(untitled /Users/nicolasborromeo/Documents/Frameworks/vulkansdk/macOS/lib/libvulkan.1.2.135.dylib)