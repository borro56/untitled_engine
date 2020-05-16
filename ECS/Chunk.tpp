#include "Chunk.h"

template<class Type, class... Types>
void AddDataRecursive(unsigned char* header, Type const& data, Types const&... rest)
{
    memcpy(header, &data, sizeof(data));

    if constexpr (sizeof...(rest) > 0)
    {
        header += sizeof(Type);
        AddDataRecursive(header, rest...);
    }
}

template<class... Types>
void Chunk::AddData(Types const&... newData)
{
    unsigned char* lastPosition = data + amount++ * sizeOfEntity;
    AddDataRecursive(lastPosition, newData...);
}