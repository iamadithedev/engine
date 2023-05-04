#pragma once

#include "window_size.hpp"

namespace base
{
    class Window
    {
    public:
        Window(std::string title, const window_size& size);

        virtual ~Window() = default;

        virtual bool create()        = 0;
        virtual void update()  const = 0;
        virtual void destroy() const = 0;

        void resize(const window_size& size);
        void close();

        [[nodiscard]] const window_size& size() const;
        [[nodiscard]] bool             closed() const;

    protected:
        std::string _title;
        window_size _size;

    private:
        bool _closed;
    };
}