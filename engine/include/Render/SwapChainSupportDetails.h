//
// Created by Nicolas Borromeo on 25/05/2020.
//

#ifndef UNTITLED_SWAPCHAINSUPPORTDETAILS_H
#define UNTITLED_SWAPCHAINSUPPORTDETAILS_H

#include "../../include/common.h"

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    vector<VkSurfaceFormatKHR> formats;
    vector<VkPresentModeKHR> presentModes;
};

#include "../../include/common.h"
#include "Vertex.h"
#include "UniformBufferObject.h"
#include "QueryFamilyIndices.h"

#endif //UNTITLED_SWAPCHAINSUPPORTDETAILS_H
