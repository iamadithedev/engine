#pragma once

#include "base/object.hpp"
#include "base/window.hpp"

namespace glfw
{
    class Window final : public base::Object<GLFWwindow*>,
                         public base::Window
    {
    public:
        Window(const std::string& title, const math::size& size);

        bool create()        final;
        void update()  const final;
        void destroy() const final;

    private:
        void _init_flags();
        void _init_callbacks();
    };
}