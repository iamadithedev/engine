#include "window.hpp"

namespace windows
{
    bool Window::create(const std::string& title, int32_t width, int32_t height)
    {
        return false;
    }

    void Window::update() const
    {
    }

    void Window::destroy() const
    {
    }

    bool Window::closing() const
    {
        return false;
    }
}