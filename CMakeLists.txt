cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled
        main.cpp
        Components/Vector3.h
        Components/Translation.h
        ECS/Archetype.cpp
        ECS/Archetype.h ECS/EntityManager.tpp ECS/EntityManager.h ECS/Entity.cpp ECS/Entity.h Components/Health.h)