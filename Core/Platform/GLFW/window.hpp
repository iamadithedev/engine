#pragma once

#include "object.hpp"
#include "base/window.hpp"

namespace glfw
{
    class Window final : public base::Object<GLFWwindow*>,
                         public base::Window
    {
    public:
        Window(int32_t width, int32_t height);

        bool create(const std::string& title) final;

        void update()  const final;
        void destroy() const final;
    };
}