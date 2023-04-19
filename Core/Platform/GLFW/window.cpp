#include "window.hpp"
#include "window_callbacks.hpp"

namespace glfw
{
    Window::Window(int32_t width, int32_t height)
        : base::Window   { width, height }
    {
    }

    bool Window::create(const std::string& title)
    {
        _handle  = glfwCreateWindow(_width, _height, title.c_str(), nullptr);
                   glfwMakeContextCurrent(_handle);

        glfwSetWindowUserPointer(_handle,    this);
        glfwSetWindowSizeCallback(_handle,  WindowCallbacks::on_size);
        glfwSetWindowCloseCallback(_handle, WindowCallbacks::on_close);

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
}