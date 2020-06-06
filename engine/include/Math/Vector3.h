#ifndef UNTITLED_VECTOR3_H
#define UNTITLED_VECTOR3_H

#include "math.h"

struct Vector3
{
    float x = 0, y = 0, z = 0;

    Vector3() : x(0), y(0), z(0) { }
    Vector3(float xyz) : x(xyz), y(xyz), z(xyz) { }
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3& b) { return Vector3(this->x + b.x, this->y + b.y, this->z + b.z); }
    Vector3 operator-(const Vector3& b) { return Vector3(this->x - b.x, this->y - b.y, this->z - b.z); }
    Vector3 operator*(const float& b) { return Vector3(this->x * b, this->y * b, this->z * b); }

    float GetMagnitude() { return sqrt(x*x + y*y + z*z); }
    float Distance(Vector3& b) { return (b - *this).GetMagnitude(); }
};

#endif