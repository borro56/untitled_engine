//
// Created by Nicolas Borromeo on 03/06/2020.
//

#ifndef UNTITLED_INPUTSYSTEM_H
#define UNTITLED_INPUTSYSTEM_H

#include "../ECS/System.h"
#include "../common.h"

class InputSystem : public System
{
    friend void onKeyEvent(GLFWwindow*, int, int, int, int);

    static InputSystem* instance;

    bool prevKeyStatus[256];
    bool keyStatus[256];

    void OnKeyEvent(GLFWwindow *window, int key, int scancode, int action, int mods); //TODO: Use friend functions

protected:
    void PrepareFrame();

public:

    InputSystem() { instance = this; }

    static InputSystem& GetInstance() { return *instance; }

    void SetWindow(GLFWwindow& window);
    bool GetKey(int key);
    bool GetKeyDown(int key);
    bool GetKeyUp(int key);
};

#endif