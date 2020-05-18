template<class... Types> void Chunk::AddData(Types const&... rest)
{
    AddDataRecursive(rest...);
    amount++;
}

template<class Type, class... Types> void Chunk::AddDataRecursive(Type const& dataToAdd, Types const&... rest)
{
    auto& type = archetype.GetType<Type>();
    auto destination = data + type.ChunkOffset() + amount * type.Size();
    memcpy(destination, &dataToAdd, sizeof(Type));

    if constexpr (sizeof...(Types) > 0)
    {
        AddDataRecursive(rest...);
    }
}

template<class Type> Type* Chunk::GetArray(const ComponentType<Type>& type) const
{
    return (Type*)(this->data + type.ChunkOffset());
}