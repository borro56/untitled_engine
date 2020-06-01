#include "TimeSystem.h"

void TimeSystem::InternalExecute(Time &time)
{
    timeReference = &time; //TODO: Analyze this
    static auto startTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto newTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();
    time.deltaTime = newTime - time.time;
    time.time = newTime;
}

void TimeSystem::InternalInit()
{
    entityManager->Create(Time()); //TODO: Analyze custom sized chunks for this scenario
}

float TimeSystem::GetTime()
{
    return timeReference->time;
}

float TimeSystem::GetDeltaTime()
{
    return timeReference ? timeReference->deltaTime : 0;
}