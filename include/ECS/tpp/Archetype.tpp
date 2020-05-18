template<class... Types> void Archetype::AddEntity(const Types &... components)
{
    GetChunk()->AddData(components...);
}

template<class Type, class... Types> void Archetype::AddType()
{
    ComponentType<Type> componentType;
    entitySize += componentType.Size();
    componentTypes.push_back(componentType);

    if constexpr (sizeof...(Types) > 0)
    {
        AddType<Types...>();
    }
}

template<class Type> ComponentType<Type>& Archetype::GetType()
{
    auto typeId = type_id<Type>;
    for(auto& type : componentTypes)
    {
        if(type.Id() == typeId)
        {
            return (ComponentType<Type>&)type;
        }
    }

    throw runtime_error("Archetype dont have the specified type");
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
        componentOffset += entityCapacity * componentType.Size();
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
    auto id = type_id<Type>;
    for(auto& type : componentTypes)
    {
        if (type.Id() == id)
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