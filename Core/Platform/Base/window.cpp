#include "window.hpp"

namespace base
{
    Window::Window(int32_t width, int32_t height)
        : _width  { width  }
        , _height { height }
        , _closed { }
    {
    }

    void Window::resize(int32_t width, int32_t height)
    {
        _width  = width;
        _height = height;
    }

    void Window::close()
    {
        _closed = true;
    }

    int32_t Window::width() const
    {
        return _width;
    }

    int32_t Window::height() const
    {
        return _height;
    }

    bool Window::closed() const
    {
        return _closed;
    }
}