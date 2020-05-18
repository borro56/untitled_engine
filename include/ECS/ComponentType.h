#ifndef UNTITLED_COMPONENTTYPE_H
#define UNTITLED_COMPONENTTYPE_H

class BaseComponentType
{
    size_t componentHash;
    size_t componentSize;
    size_t chunkOffset;

protected:
    BaseComponentType(size_t componentHash, size_t componentSize) :
            componentHash(componentHash),
            componentSize(componentSize) { }

public:
    size_t ComponentSize() { return componentSize; }
    size_t ComponentHash() { return componentHash; }
    size_t ChunkOffset() { return chunkOffset; }

    void ChunkOffset(size_t chunkOffset) { this->chunkOffset = chunkOffset; } //TODO: Buscar otra forma de hacer propiedades
};

template<class Type>
class ComponentType : public BaseComponentType
{
public:
    ComponentType() : BaseComponentType(typeHash<Type>(), sizeof(Type)) {}
};

#endif