#ifndef UNTITLED_RENDERABLE_H
#define UNTITLED_RENDERABLE_H


#include "Mesh.h"

struct Renderable
{
    int renderId;
    Mesh mesh;

    Renderable(int renderId, Mesh mesh) : renderId(renderId), mesh(mesh) { }
};

#endif //UNTITLED_RENDERABLE_H