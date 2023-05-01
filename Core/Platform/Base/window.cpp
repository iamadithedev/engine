#include "window.hpp"

namespace base
{
    Window::Window(std::string title, const window_size& size)
        : _title  { std::move(title) }
        , _size   { size }
        , _closed { }
    {
    }

    void Window::resize(const window_size& size)
    {
        _size = size;
    }

    void Window::close()
    {
        _closed = true;
    }

    const window_size& Window::size() const
    {
        return _size;
    }

    bool Window::closed() const
    {
        return _closed;
    }
}