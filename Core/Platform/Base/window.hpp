#pragma once

#include "size.hpp"

namespace base
{
    class Window
    {
    public:
        Window(std::string title, const math::size& size);

        virtual ~Window() = default;

        virtual bool create()        = 0;
        virtual void update()  const = 0;
        virtual void destroy() const = 0;

        void resize(const math::size& size);
        void close();

        [[nodiscard]] const math::size& size() const;
        [[nodiscard]] bool            closed() const;

    protected:
        std::string _title;
        math::size  _size;

    private:
        bool _closed;
    };
}