#include "input.hpp"
#include "window.hpp"

namespace glfw
{
    bool Input::mouse_pressed(const base::Window* window, input::Button button) const
    {
        return glfwGetMouseButton(((glfw::Window*)window)->handle(), (int32_t)button) == GLFW_PRESS;
    }

    bool Input::key_pressed(const base::Window* window, input::Key key) const
    {
        return glfwGetKey(((glfw::Window*)window)->handle(), (int32_t)key) == GLFW_PRESS;
    }
}