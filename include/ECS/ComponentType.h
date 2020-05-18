#ifndef UNTITLED_COMPONENTTYPE_H
#define UNTITLED_COMPONENTTYPE_H

class BaseComponentType
{
    size_t id;
    size_t size;
    size_t chunkOffset;

protected:
    BaseComponentType(size_t id, size_t componentSize) :
            id(id),
            size(componentSize) { }

public:
    size_t Size() { return size; }
    size_t Id() { return id; }
    size_t ChunkOffset() { return chunkOffset; }

    void ChunkOffset(size_t chunkOffset) { this->chunkOffset = chunkOffset; }
};

template<class Type>
class ComponentType : public BaseComponentType
{
public:
    ComponentType() : BaseComponentType(type_id<Type>, sizeof(Type)) {}
};

#endif