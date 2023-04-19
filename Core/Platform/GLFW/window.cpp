#include "window.hpp"

namespace glfw
{
    bool Window::create(const std::string& title, int32_t width, int32_t height)
    {
        _handle  = glfwCreateWindow(width, height, title.c_str(), nullptr);
                   glfwMakeContextCurrent(_handle);

        return _handle != nullptr;
    }

    void Window::update() const
    {
        glfwSwapBuffers(_handle);
    }

    void Window::destroy() const
    {
        glfwDestroyWindow(_handle);
    }

    bool Window::closing() const
    {
        return glfwWindowShouldClose(_handle);
    }
}