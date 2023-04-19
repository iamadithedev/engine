#pragma once

namespace base
{
    class Window
    {
    public:
        virtual ~Window() = default;

        virtual bool create(const std::string& title, int32_t width, int32_t height) = 0;

        virtual void update()  const = 0;
        virtual void destroy() const = 0;

        [[nodiscard]] virtual bool closing() const = 0;
    };
}