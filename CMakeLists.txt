cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled
        src/main.cpp
        include/Math/Vector3.h
        include/Components/Translation.h
        include/ECS/tpp/Archetype.tpp
        include/ECS/Archetype.h
        include/ECS/tpp/EntityManager.tpp
        include/ECS/EntityManager.h
        src/ECS/Entity.cpp
        include/ECS/Entity.h
        include/Components/Health.h
        include/ECS/tpp/Chunk.tpp
        include/ECS/Chunk.h
        src/ECS/Archetype.cpp
        include/ECS/ComponentType.h
        include/common.h
        src/ECS/Chunk.cpp
        include/Components/Speed.h include/ECS/System.h app/TestSystem.cpp app/TestSystem.h)