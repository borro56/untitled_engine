#include "../../include/ECS/SystemThread.h"

void SystemThread::Execute()
{
    archetype.ExecuteSystem(chunk);
}