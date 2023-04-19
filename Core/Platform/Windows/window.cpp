#include "window.hpp"

namespace windows
{
    Window::Window(int32_t width, int32_t height)
        : base::Window   { width, height }
    {
    }

    bool Window::create(const std::string& title)
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