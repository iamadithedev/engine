#pragma once

#include "base/input.hpp"

namespace glfw
{
    class Input final : public base::Input
    {
    public:
        bool mouse_pressed(const base::Window* window, input::Button button) const final;
        bool key_pressed(const   base::Window* window, input::Key    key)    const final;

        vec2 mouse_position(const base::Window* window) const final;
    };
}