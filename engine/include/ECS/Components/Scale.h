#ifndef UNTITLED_SCALE_H
#define UNTITLED_SCALE_H

#include "../../Math/Vector3.h"

struct Scale
{
    Vector3 value;

    Scale() : value(1,1,1) {}
    Scale(Vector3 value) : value(value) {}
};


#endif