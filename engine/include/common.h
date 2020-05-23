#ifndef UNTITLED_COMMON_H
#define UNTITLED_COMMON_H

#include <cstddef>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <thread>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

using namespace std;

inline int type_id_seq = 0;
template< typename > inline const int type_id = type_id_seq++;

#endif