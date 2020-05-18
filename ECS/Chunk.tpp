#include "../common.h"
#include "Chunk.h"

template<class... Types> void Chunk::AddData(Types const&... rest)
{
    AddDataRecursive(rest...);
    amount++;
}

template<class Type, class... Types> void Chunk::AddDataRecursive(Type const& data, Types const&... rest)
{
    auto type = archetype->GetType<Type>();
    auto destination = this->data + type->chunkOffset + amount * type->componentSize;
    memcpy(destination, &data, sizeof(Type));

    if constexpr (sizeof...(Types) > 0)
    {
        AddDataRecursive(rest...);
    }
}

template<class Type>
Type *Chunk::GetArray(ComponentType<Type> &type)
{
    return (Type*)this->data + type.chunkOffset;
}
