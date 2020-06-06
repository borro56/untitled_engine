#include "../../include/Input/InputSystem.h"

void onKeyEvent(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    InputSystem::GetInstance().OnKeyEvent(window, key, scancode, action, mods);
}


void InputSystem::SetWindow(GLFWwindow &window)
{
    glfwSetKeyCallback(&window, onKeyEvent);
}

void InputSystem::OnKeyEvent(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        keyStatus[key] = true;
    }

    if (action == GLFW_RELEASE)
    {
        keyStatus[key] = false;
    }
}

bool InputSystem::GetKey(int key)
{
    return keyStatus[key];
}

bool InputSystem::GetKeyDown(int key)
{
    return !prevKeyStatus[key] && keyStatus[key];
}

bool InputSystem::GetKeyUp(int key)
{
    return prevKeyStatus[key] && !keyStatus[key];
}


void InputSystem::PrepareFrame()
{
    copy(keyStatus, keyStatus + 256, prevKeyStatus);
}

InputSystem* InputSystem::instance;