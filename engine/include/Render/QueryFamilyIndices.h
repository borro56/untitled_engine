//
// Created by Nicolas Borromeo on 24/05/2020.
//

#ifndef UNTITLED_QUERYFAMILYINDICES_H
#define UNTITLED_QUERYFAMILYINDICES_H

struct QueueFamilyIndices {
    optional<uint32_t> graphicsFamily;
    optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

#include "../../include/common.h"
#include "Vertex.h"
#include "UniformBufferObject.h"

#endif //UNTITLED_QUERYFAMILYINDICES_H
