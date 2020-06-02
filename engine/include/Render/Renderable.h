#ifndef UNTITLED_RENDERABLE_H
#define UNTITLED_RENDERABLE_H


#include "Mesh.h"

struct Renderable
{
    int renderId;
    Mesh mesh;
    VkPipeline pipeline; //TODO: Create material

    Renderable(int renderId, Mesh mesh, VkPipeline pipeline) : renderId(renderId), mesh(mesh), pipeline(pipeline) { }
};

#endif //UNTITLED_RENDERABLE_H