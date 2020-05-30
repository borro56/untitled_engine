#ifndef UNTITLED_VECTOR3_H
#define UNTITLED_VECTOR3_H

struct Vector3
{
    float x, y, z;

    Vector3() : x(0), y(0), z(0) { }
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
};

#endif