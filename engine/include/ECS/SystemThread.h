//
// Created by Nicolas Borromeo on 21/05/2020.
//

#ifndef UNTITLED_SYSTEMTHREAD_H
#define UNTITLED_SYSTEMTHREAD_H

#include "../common.h"

class SystemThread
{
    class Chunk& chunk;
    class Archetype& archetype;
    thread thread;

public:
    SystemThread(Chunk& chunk, Archetype& archetype) :
            chunk(chunk),
            archetype(archetype),
            thread(&SystemThread::Execute, this)
    {

    }

    class thread& Thread() { return thread; } //TODO: See why cant set this as const

    void Execute();
};

#include "Archetype.h"

#endif //UNTITLED_SYSTEMTHREAD_H
