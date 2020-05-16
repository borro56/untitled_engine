#include "Archetype.h"

template<class... Types>
void Archetype::AddEntity(const Types &... components)
{
    GetChunk()->AddData(components...);
}