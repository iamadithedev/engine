#include "window_callbacks.hpp"
#include "window.hpp"

namespace glfw
{
    void WindowCallbacks::on_size(GLFWwindow* handle, int32_t width, int32_t height)
    {
        get_window(handle)->resize({ width, height });
    }

    void WindowCallbacks::on_close(GLFWwindow* handle)
    {
        get_window(handle)->close();
    }

    Window* WindowCallbacks::get_window(GLFWwindow* handle)
    {
        return ((Window*)glfwGetWindowUserPointer(handle));
    }
}