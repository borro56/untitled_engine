#ifndef UNTITLED_COMMON_H
#define UNTITLED_COMMON_H

#define GLFW_INCLUDE_VULKAN
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <cstddef>
#include <vector>
#include <iostream>
#include "mingw.thread.h"//#include <thread>
#include "mingw.mutex.h"
#include <optional>
#include <array>
#include <stdexcept>
#include <cstdlib>
#include <set>
#include <cstdint>
#include <fstream>
#include <map>

#include <math.h>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <chrono>
#include <unordered_map>

using namespace std;

inline int type_id_seq = 0;
template< typename > inline const int type_id = type_id_seq++;

#endif