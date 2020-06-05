#ifndef UNTITLED_RENDERABLE_H
#define UNTITLED_RENDERABLE_H


#include "Mesh.h"

struct Renderable
{
    Mesh mesh;
    VkPipeline pipeline;

    Renderable(Mesh mesh, VkPipeline pipeline) : mesh(mesh), pipeline(pipeline) { }
};

#endif //UNTITLED_RENDERABLE_H