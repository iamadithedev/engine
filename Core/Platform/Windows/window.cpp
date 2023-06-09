#include "window.hpp"

namespace windows
{
    Window::Window(const std::string& title, const window_size& size)
        : base::Window { title, size }
    {
    }

    bool Window::create()
    {
        return false;
    }

    void Window::update() const
    {
    }

    void Window::destroy() const
    {
    }
}