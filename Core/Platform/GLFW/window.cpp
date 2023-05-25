#include "window.hpp"
#include "window_callbacks.hpp"

namespace glfw
{
    Window::Window(const std::string& title, const math::size& size)
        : base::Window { title, size }
    {
    }

    bool Window::create()
    {
        _init_flags();

        _handle = glfwCreateWindow(_size.width, _size.height, _title.c_str(), nullptr);
                  glfwMakeContextCurrent(_handle);

        _init_callbacks();

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

    void Window::_init_flags()
    {
        if (_fixed_size) {
            glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        }
    }

    void Window::_init_callbacks()
    {
        glfwSetWindowUserPointer(_handle,   this);
        glfwSetWindowSizeCallback(_handle,  WindowCallbacks::on_size);
        glfwSetWindowCloseCallback(_handle, WindowCallbacks::on_close);
    }
}