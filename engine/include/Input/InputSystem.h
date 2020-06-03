//
// Created by Nicolas Borromeo on 03/06/2020.
//

#ifndef UNTITLED_INPUTSYSTEM_H
#define UNTITLED_INPUTSYSTEM_H

#include "../ECS/System.h"
#include "../common.h"

class InputSystem : public System
{
    static InputSystem* instance;

    bool keyStatus[256];
public:

    InputSystem() { instance = this; }

    static InputSystem& GetInstance() { return *instance; }

    void SetWindow(GLFWwindow& window);
    bool GetKey(int key);

    void OnKeyEvent(GLFWwindow *window, int key, int scancode, int action, int mods); //TODO: Use friend functions

};

#endif