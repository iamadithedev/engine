#pragma once

#include "base/input.hpp"

namespace glfw
{
    class Input final : public base::Input
    {
    public:
        bool mouse_pressed(const base::Window* window, int32_t button) const final;
        bool key_pressed(const   base::Window* window, input::Key key) const final;
    };
}