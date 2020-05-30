#ifndef UNTITLED_ROTATION_H
#define UNTITLED_ROTATION_H

#include "../../Math/Vector3.h"

struct Rotation
{
    Vector3 value;

    Rotation() {}
    Rotation(Vector3 value) : value(value) {}
};

#endif //UNTITLED_ROTATION_H