template<class... Types> void Archetype::AddEntity(const Types &... components)
{
    GetChunk()->AddData(components...);
}

template<class Type, class... Types> void Archetype::AddType()
{
    ComponentType<Type> componentType;
    entitySize += componentType.ComponentSize();
    componentTypes.push_back(componentType);

    if constexpr (sizeof...(Types) > 0)
    {
        AddType<Types...>();
    }
}

template<class Type> ComponentType<Type>& Archetype::GetType()
{
    auto hash = typeHash<Type>();
    for(auto& type : componentTypes)
    {
        if(type.ComponentHash() == hash)
        {
            return (ComponentType<Type>&)type;
        }
    }

    throw exception(); //TODO: Improve exception message
}

template <class... Types> Archetype Archetype::Create()
{
    Archetype archetype;

    archetype.componentTypes.reserve(sizeof...(Types));
    archetype.AddType<Types...>();

    auto entityCapacity = CHUNK_SIZE / archetype.entitySize;
    auto componentOffset = 0;

    for(auto& componentType : archetype.componentTypes)
    {
        componentType.ChunkOffset(componentOffset);
        componentOffset += entityCapacity * componentType.ComponentSize();
    }

    return archetype;
}

template<class... Types>
bool Archetype::HasTypes()
{
    if (sizeof...(Types) != componentTypes.size()) return false;
    return HasTypesRecursive<Types...>();
}

template<class Type, class... Types>
bool Archetype::HasTypesRecursive()
{
    auto hash = typeHash<Type>();
    for(auto& type : componentTypes)
    {
        if (type.ComponentHash() == hash)
        {
            if constexpr (sizeof...(Types) > 0)
            {
                return HasTypesRecursive<Types...>();
            }

            return true;
        }
    }

    return false;
}