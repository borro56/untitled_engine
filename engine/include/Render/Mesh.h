#ifndef UNTITLED_MESH_H
#define UNTITLED_MESH_H

#include "../common.h"

struct Mesh
{
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    int indicesCount;
};

#endif