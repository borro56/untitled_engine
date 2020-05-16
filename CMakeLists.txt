cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled
        main.cpp
        Math/Vector3.h
        Components/Translation.h
        ECS/Archetype.tpp
        ECS/Archetype.h
        ECS/EntityManager.tpp
        ECS/EntityManager.h
        ECS/Entity.cpp
        ECS/Entity.h
        Components/Health.h
        ECS/Chunk.tpp
        ECS/Chunk.h
        ECS/Archetype.cpp
        ECS/EntityManager.cpp)