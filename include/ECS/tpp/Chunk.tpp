template<class... Types> void Chunk::AddData(Types const&... rest)
{
    AddDataRecursive(rest...);
    amount++;
}

template<class Type, class... Types> void Chunk::AddDataRecursive(Type const& dataToAdd, Types const&... rest)
{
    auto& type = archetype.GetType<Type>();
    auto destination = data + type.ChunkOffset() + amount * type.ComponentSize();
    memcpy(destination, &dataToAdd, sizeof(Type));

    if constexpr (sizeof...(Types) > 0)
    {
        AddDataRecursive(rest...);
    }
}

//TODO: Evaluate if its better to return the array as before
template<class Type> Type &Chunk::GetAt(ComponentType<Type> &type, int index)
{
    return ((Type*)(this->data + type.ChunkOffset()))[index];
}