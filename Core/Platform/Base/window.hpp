#pragma once

namespace base
{
    class Window
    {
    public:
        Window(int32_t width, int32_t height);

        virtual ~Window() = default;

        virtual bool create(const std::string& title) = 0;

        virtual void update()  const = 0;
        virtual void destroy() const = 0;

        void resize(int32_t width, int32_t height);
        void close();

        [[nodiscard]] int32_t width()  const;
        [[nodiscard]] int32_t height() const;

        [[nodiscard]] bool    closed() const;

    protected:
        int32_t _width;
        int32_t _height;

        bool _closed;
    };
}