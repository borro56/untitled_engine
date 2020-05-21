cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled
        app/src/main.cpp
        engine/include/Math/Vector3.h
        engine/include/Components/Translation.h
        engine/include/ECS/tpp/Archetype.tpp
        engine/include/ECS/Archetype.h
        engine/include/ECS/tpp/EntityManager.tpp
        engine/include/ECS/EntityManager.h
        engine/include/ECS/Entity.h
        engine/include/Components/Health.h
        engine/include/ECS/tpp/Chunk.tpp
        engine/include/ECS/Chunk.h
        engine/src/ECS/Archetype.cpp
        engine/include/ECS/ComponentType.h
        engine/include/common.h
        engine/include/Components/Speed.h engine/include/ECS/System.h app/include/TestSystem.h engine/src/ECS/EntityManager.cpp)