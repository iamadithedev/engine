#include "window.hpp"

namespace base
{
    Window::Window(std::string title, const math::size& size)
        : _title  { std::move(title) }
        , _size   { size }
        , _fixed_size { }
        , _closed     { }
    {
    }

    void Window::resize(const math::size& size)
    {
        _size = size;
    }

    void Window::fixed_size()
    {
        _fixed_size = true;
    }

    void Window::close()
    {
        _closed = true;
    }

    const math::size& Window::size() const
    {
        return _size;
    }

    bool Window::closed() const
    {
        return _closed;
    }

    bool Window::fixed_size() const
    {
        return _fixed_size;
    }
}