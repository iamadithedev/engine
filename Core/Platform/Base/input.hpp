#pragma once

#include "window.hpp"

#include "input_keys.hpp"
#include "input_buttons.hpp"

namespace base
{
    class Input
    {
    public:
        virtual ~Input() = default;

        virtual bool mouse_pressed(const Window* window, input::Button button) const = 0;
        virtual bool key_pressed(const   Window* window, input::Key    key)    const = 0;
    };
}