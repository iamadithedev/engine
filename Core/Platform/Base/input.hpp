#pragma once

#include "window.hpp"

namespace base
{
    class Input
    {
    public:
        virtual ~Input() = default;

        virtual bool mouse_pressed(const Window* window, int32_t button) const = 0;
        virtual bool key_pressed(const   Window* window, int32_t key)    const = 0;
    };
}