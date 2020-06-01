#include "TimeSystem.h"

void TimeSystem::InternalExecute(Time &time)
{
    static auto startTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto newTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();
    time.deltaTime = newTime - time.time;
    time.time = newTime;
}

void TimeSystem::InternalInit()
{
    entityManager->Create(Time());
}