

#include "ComponentType.h"
#include "../common.h"


template <class Type> ComponentType ComponentType::Create()
{
    ComponentType componentType;
    componentType.componentSize = sizeof(Type);
    componentType.componentHash = typeHash<Type>();
    return componentType;
}