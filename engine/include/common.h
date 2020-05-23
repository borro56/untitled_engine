#ifndef UNTITLED_COMMON_H
#define UNTITLED_COMMON_H

#define GLFW_INCLUDE_VULKAN
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <cstddef>
#include <vector>
#include <iostream>
#include <thread>
#include <optional>

#include <stdio.h>
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

using namespace std;

inline int type_id_seq = 0;
template< typename > inline const int type_id = type_id_seq++;

#endif