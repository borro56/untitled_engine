//
// Created by Nicolas Borromeo on 24/05/2020.
//

#ifndef UNTITLED_UNIFORMBUFFEROBJECT_H
#define UNTITLED_UNIFORMBUFFEROBJECT_H

struct UniformBufferObject {
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 proj;
};

#include "../../include/common.h"
#include "Vertex.h"

#endif //UNTITLED_UNIFORMBUFFEROBJECT_H
