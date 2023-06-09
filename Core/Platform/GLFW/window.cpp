#include "window.hpp"
#include "window_callbacks.hpp"

namespace glfw
{
    Window::Window(const std::string& title, const window_size& size)
        : base::Window { title, size }
    {
    }

    bool Window::create()
    {
        _handle  = glfwCreateWindow(_size.width, _size.height, _title.c_str(), nullptr);
                   glfwMakeContextCurrent(_handle);

        glfwSetWindowUserPointer(_handle,   this);
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