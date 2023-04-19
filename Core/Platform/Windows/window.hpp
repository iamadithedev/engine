#pragma once

#include "object.hpp"
#include "base/window.hpp"

namespace windows
{
    class Window final : public base::Window
    {
    public:
        bool create(const std::string& title, int32_t width, int32_t height) final;

        void update()  const final;
        void destroy() const final;

        [[nodiscard]] bool closing() const final;
    };
}