#include "TimeSystem.h"

void TimeSystem::PrepareFrame()
{
    static auto startTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto newTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();
    deltaTime = newTime - time;
    time = newTime;
}

float TimeSystem::GetTime()
{
    return time;
}

float TimeSystem::GetDeltaTime()
{
    return deltaTime;
}