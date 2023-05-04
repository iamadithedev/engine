#include "window_callbacks.hpp"
#include "window.hpp"

namespace glfw
{
    void WindowCallbacks::on_size(GLFWwindow* handle, int32_t width, int32_t height)
    {
        ((Window*)glfwGetWindowUserPointer(handle))->resize({ width, height });
    }

    void WindowCallbacks::on_close(GLFWwindow* handle)
    {
        ((Window*)glfwGetWindowUserPointer(handle))->close();
    }
}