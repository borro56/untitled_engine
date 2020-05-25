#ifndef UNTITLED_TRANSLATION_H
#define UNTITLED_TRANSLATION_H

#include "../../Math/Vector3.h"

struct Translation
{
    Vector3 value;

    Translation() {}
    Translation(Vector3 value) : value(value) {}
};

#endif